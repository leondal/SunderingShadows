//Added a check for move ok to stop items being lost in the void.  Circe 12/14/03
//Last change was August 24, 2003
//      /std/spell_vend.c
//      a standard object that sells spells in shops
//      created by Vashkar@ShadowGate by modifying /std/comp_vend.c
//      which was created by Melnmarn@ShadowGate
// 	   	Note from Tristan@shadowgate Made to work
// 		Gratuitous shit code doesn't describe this crap
//		The comp_vend was okay but this spell_vend is pure shit


#include <std.h>
#include <money.h>
#include <daemons.h>
#include <move.h>

#define SCROLL_PATH "/d/magic/scroll"
#define LINE "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
#define BACKUP_DIR "/d/save/spellbook/backup_books"
#define SAVE_DIR "/d/save/spellbook/save"

inherit MONSTER;

string *Available, tmpstr;
int number;
mapping spellnames, backing;

mixed sort_items(object one, object two);
int set_spells_sold(mapping map);
int has_comp_bag(object targ);

void create()
{
   ::create();
}

void set_name(string str)
{
   ::set_name(str);
   if(file_exists(SAVE_DIR+"/"+query_name()+".spell_seller.o") )
      restore_object(SAVE_DIR+"/"+query_name()+".spell_seller");
   if(!backing) backing = ([]);
}

void init()
{
   ::init();
   add_action("__Buy", "buy");
   add_action("__List", "list");
   add_action("__Help", "help");
   add_action("__Pickup", "pickup");
   add_action("__Sell","sell");
   add_action("__Check","check");
}

int __Pickup(string str){
	int i,j,k,l;
	string *bdspell = ({});
    object tmpbook;
    string *spells;
    mapping newlist = ([]);

    if(member_array(str,({ "book","spell book","spellbook"})) != -1){
        if(member_array(TPQN,keys(backing)) == -1) return notify_fail("You didn't leave a spell book here!\n");
        if(time() - backing[TPQN] > 1){
            if(time() - backing[TPQN] < 200){
                write("%^ORANGE%^I just started copying the book, it takes me about twenty minutes to copy a spell book.");
                return 1;
            }
            if(time() - backing[TPQN] < 600){
                write("%^ORANGE%^I'm not even halfway done with copying the book, come back later.");
                return 1;
            }
            if(time() - backing[TPQN] < 1000){
                write("%^ORANGE%^I have most of the book copied, give me a bit more time...");
                return 1;
            }
            if(time() - backing[TPQN] < 1200){
                write("%^ORANGE%^Almost done...almost done...");
                return 1;
            }
            write("%^ORANGE%^"+query_cap_name()+" hands you your spellbook!");
        }
        map_delete(backing, TPQN);
        save_object(SAVE_DIR+"/"+query_name()+".spell_seller");
        tmpbook=new("/d/magic/spellbook");
        tmpbook->restore_me(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup");
        if((int)(tmpbook->move(TP))!=MOVE_OK){
            write("%^MAGENTA%^"+TO->query_name()+" says%^RESET%^: You can't carry your book, I will drop it on the floor.");
            tmpbook->move(ETP);
        }
        write("%^MAGENTA%^"+TO->query_name()+" says%^RESET%^: Here is your spell book back, come back any time to pick up the backup of it.\n");
        return 1;
    }
   if(member_array(str,({ "backup","back up"})) != -1){
      if(backing[TPQN]) return notify_fail("You must pick up your original spellbook first!\n");
      if(!file_exists(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup.o"))
         return notify_fail("You never made a backup of your spell book!\n");
      tmpbook=new("/d/magic/spellbook");
      tmpbook->restore_me(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup");
      spells = tmpbook->query_spells();
      i = sizeof(spells);
      j = random(i);
      for(l= 0;l<j;l++){
        	k = random(i);
        	bdspell += ({spells[k]});
      }
      spells -= ({bdspell});
      j = sizeof(spells);
      for(i=0;i<j;i++){
        	k = tmpbook->query_spellbook(spells[i]);
        	newlist[spells[i]]=k;
      }
      tmpbook->set_spells(newlist);
      write("You notice that the book looks much thinner!");
      if((int)(tmpbook->move(TP))!=MOVE_OK){
         write("%^MAGENTA%^"+TO->query_name()+" says%^RESET%^: You can't carry your book, I will drop it on the floor.");
         tmpbook->move(ETP);
      }
      tmpbook->resetdesc();
      rm(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup.o");
      write("Here is your backup copy of the spell book, enjoy!");
      return 1;
   }
   return notify_fail("Pickup what?\n");
}

int __Buy(mixed str){
   object ob, newbook, newbag;
   string magetype;
   int pgold,cost, success;

   if(!str) return notify_fail("%^BOLD%^Syntax: buy <itemname> or <itemnumber>\n");
   if(!TP->is_class("mage") && !TP->is_class("bard") && !TP->is_class("sorcerer"))
      return notify_fail("Sorry, I sell nothing to non-magi such as yourself.");
   if(member_array(str,({"book","spellbook","spell book"})) != -1){
      if(!TP->query_funds("gold",100)){
         write("%^RED%^You don't have enough money to buy a new spellbook!");
         return 1;
      }
      TP->use_funds("gold",100);
      magetype=MAGIC_D->query_title(TP);
      write("%^CYAN%^Here is a spellbook fit for a "+magetype+" like yourself.");
      newbook = new("/d/magic/spellbook"); //added move code Circe 12/14/03
      if (newbook->move(TP) != MOVE_OK){
         newbook->move(ETP);
         write("%^MAGENTA%^"+TO->query_name()+" says%^RESET%^: You can't carry your book, I will drop it on the floor.");
      }
      return 1;
   }
   if(str == "backup"){
      write("%^RED%^Buy a backup of what?");
      return 1;
   }
   tmpstr = 0;
   if(!sscanf(str,"backup of %s",tmpstr)) sscanf(str,"back up of %s",tmpstr);
   if(tmpstr && tmpstr != ""){
      if(!TP->query_funds("gold",2000)){
         write("%^RED%^You don't have enough gold to buy a backup copy of your spell book!");
         return 1;
      }
      if(!ob=present(tmpstr,TP)){
         write("%^RED%^You don't have a "+tmpstr+" to make a copy of!");
         return 1;
      }
      if(!ob->is_spellbook()){
         write("%^RED%^That's not a spell book!");
         return 1;
      }
      TP->use_funds("gold",2000);
      write("%^GREEN%^You relinquish your book to "+query_cap_name()+".\n%^MAGENTA%^"+query_cap_name()+"%^RESET%^: I will have your spell book copied in twenty minutes. Come back then to <pickup spell book>");
      ob->save_me(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup");
      ob->save_me("/d/save/spellbook/save_books/"+TPQN+"_"+query_name()+".backup");
      ob->remove();
      backing += ([ TPQN : time() ]);
      save_object(SAVE_DIR+"/"+query_name()+".spell_seller");
      return 1;
   }
   if(member_array(str,({"bag","component bag", "components bag","spell components bag", "spell component bag"})) != -1){
      if(!TP->query_funds("gold",10)){
         write("%^RED%^You don't have enough gold to buy a new components bag!");
         return 1;
      }
/*
    if(has_comp_bag(TP)) {
      write("%^RED%^You already have one of those, you don't need two.");
      return 1;
    }
*/
      TP->use_funds("gold",10);
      write("%^CYAN%^Here is your components bag.");
      newbag = new("/d/magic/comp_bag"); //added move code Circe 12/14/03
      if (newbag->move(TP) != MOVE_OK){
         newbag->move(ETP);
         write("You can't carry your bag, I will drop it on the floor.");
      }
      return 1;
   }
	if(!sscanf(str,"%d",number)){
      if(member_array(str,Available) == -1)
         return notify_fail("Sorry, I'm not selling any spells of "+str+".\n");
      else{
         number = member_array(str,Available);
      }
   }
  if (number > ( sizeof(Available) - 1))
      return notify_fail("There is no spell number %^BOLD%^"+number+".\n");
   cost = spellnames[Available[number]];
   pgold = (int)TP->query_exp();
   if(pgold < cost)
   {
      write("%^RED%^You don't have enough experience points to buy the spell of "+Available[number]+"'s!");
      return 1;
   }
   if((int)TP->set_XP_tax(cost, 0, "improvement") == -1)
   {
       TP->add_exp(-1 * cost);
   }
   TP->resetLevelForExp(0);
   tell_object(TP,"%^RED%^Subtracting "+cost+" experience points.%^RESET%^");
   write("%^CYAN%^Here is a scroll with the magical text of %^YELLOW%^"+Available[number]+"%^CYAN%^ written upon it.");
   ob = new(SCROLL_PATH);
   ob->set_spell_name(Available[number]);
   if((int)(ob->move(TP))!=MOVE_OK){
      write("%^MAGENTA%^"+TO->query_name()+" says%^RESET%^: You can't carry the scroll, I will drop it on the floor.");
      ob->move(ETP);
      return 1;
   }
   return 1;
}

int __List(string str){
   string bigstring;
   int inc,lines;

   lines = to_int(TP->getenv("LINES"));
   lines -= 2;
   if(!str) return notify_fail("List what?\n");
   if(strsrch(str,"spells") == -1) return notify_fail("I don't sell that!\n");
   Available = sort_array(Available,"sort_strings",TO);
   bigstring = LINE;
   for(inc = 0; inc < sizeof(Available);inc++){
      bigstring += sprintf("%3d: ",inc);
      bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^experience points\n",capitalize(Available[inc]),spellnames[Available[inc]]);
      if(((inc+1)%lines == 0) &&(inc > 1)) bigstring += (LINE + LINE);
   }
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Spell book", 100);
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Components bag", 10);
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Backup", 2000);
   bigstring += LINE;
   TP->more(explode(bigstring,"\n"));
   return 1;
}

string sort_strings(string one, string two)
{
    return strcmp(one, two);
}

int set_spells_sold(mapping map)
{
    int inc, temp;
    string *str;

    spellnames = map;
    Available = keys(map);
    return 1;
}

string *query_spells()
{
    return Available;
}

mixed sort_items(object one, object two)
{
    return strcmp(one->query_short(), two->query_short());
}

int __Help(string nothing)
{
    if (nothing != "store" && nothing != "shop")
	return 0;
    write("%^CYAN%^%^ULINE%^Spell store%^RESET%^

%^ORANGE%^<list spells>%^RESET%^
    The list command will list all spells available in this shop.

%^ORANGE%^<buy %^ORANGE%^%^ULINE%^SPELL_NAME%^RESET%^%^ORANGE%^|book|backup of book>%^RESET%^
    This will let you buy a spell, spell book, or a backup of your spell book that the shopkeeper will hold for you. If you want to buy a spell, you may either enter the number of the spell you want to buy, or its name.
    e.g. %^ORANGE%^<buy 5>%^RESET%^ will buy spell #5 on the list
    e.g. %^ORANGE%^<buy magic missile>%^RESET%^ will buy the spell of magic missile

%^ORANGE%^<pickup spell book>%^RESET%^ or %^ORANGE%^<pickup backup>%^RESET%^
    Get a spell book that you left here to be backed up, or get the backup copy of a book you had backed up in this store.

%^ORANGE%^<check backup>%^RESET%^ or %^ORANGE%^<check back up>%^RESET%^
    This will check if you have a backup in the shop.

%^ORANGE%^<help store>%^RESET%^
    Displays this text.
");
    return 1;
}

int __Sell(string str){
   object ob;
   int level;

   if(!str) return 0;
   if(!ob = present(str,TP)) return notify_fail("You don't have that item.\n");
   if(!ob->is_scroll()) return notify_fail("I only buy scrolls.\n");
// was this, changing to use query_value to fix problems with safe scrolls *Styx* 8/24/03
//   level = ob->query_spell_level();
//   TP->add_money("gold",(level*level)*100);
   TP->add_money("gold",ob->query_value());
   write(query_cap_name()+" takes the scroll and hands you "+ob->query_value()+" gold.");
   tell_room(ETO,query_cap_name()+" takes a scroll from "+TPQCN+" and hands "+TP->query_objective()+" some money.",TP);
   ob->remove();
   return 1;
}

int __Check(string str){
   if((str != "backup") && (str != "back up"))
      return 0;
   if(backing[TPQN]) return notify_fail("Your original spellbook is still in the shop! Pick it up first.\n");
   if(!file_exists(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup.o")) {
      tell_object(TP,"%^RED%^You don't have a backup spellbook here!");
      return 1;
   }
   if(file_exists(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup.o")) {
      tell_object(TP,"%^GREEN%^There is a copy of your spellbook here!");
      return 1;
   }
   return 0;
}

int has_comp_bag(object targ){
    object *inv;
    int x;

    inv = deep_inventory(targ);
    for(x = 0;x<sizeof(inv);x++)
      if(inv[x]->id("components bag")) return 1;
    return 0;
}

int is_vendor() { return 1; }

/**
 * Generates random spell list from list of all mage spells
 */
mapping gen_spells_sold(int maxrand)
{
    mapping all_spells, tmp;
    string *all_spell_names, spellfile;
    int lvl, i, j, k;
    object spell;

    all_spells = MAGIC_D->query_index("mage");
    all_spell_names = keys(all_spells);

    all_spell_names = map_array(all_spell_names, (: MAGIC_D->get_spell_file_name($1):));

//    all_spell_names=filter_array(all_spell_names,(:file_exists($1):));
    all_spells = ([]);
    foreach(spellfile in all_spell_names) {
        if (catch(spell = new(spellfile)))
            continue;
        if (lvl = spell->query_spell_level("mage"))
            if (spell->query_feat_required("mage") == "me")
                all_spells[spell->query_spell_name()] =
                    (2132 * lvl * lvl - 3522 * lvl + 3870 +
                     roll_dice(lvl, 100));
        spell->remove();
    }

    tmp = ([]);
    all_spell_names = keys(all_spells);
    k = sizeof(all_spell_names);
    for (i = 1; i < maxrand; i++) {
        j = random(k);
        tmp[all_spell_names[j]] = all_spells[all_spell_names[j]];
    }
    return tmp;

}
