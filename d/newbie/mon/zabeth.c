//      /std/spell_vend.c
//      a standard object that sells spells in shops
//      created by Vashkar@ShadowGate by modifying /std/comp_vend.c
//      which was created by Melnmarn@ShadowGate
// 	   	Note from Tristan@shadowgate Made to work
// 		Gratuitous shit code doesn't describe this crap 
//		The comp_vend was okay but this spell_vend is pure shit

//  Styx & Garrett adapted her from Wizbert for Newbietown since he works.
//  Restricted spells available, lowered backup costs and amount paid for
//  scrolls.

#include <std.h>
#include <money.h>
#include <daemons.h>
#include <move.h>

#define LINE "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n"
#define SCROLL_PATH "/d/magic/scroll"
#define BACKUP_DIR "/d/magic/spellbook/backup_books"
#define SAVE_DIR "/d/magic/spellbook/save"

inherit "/std/spell_vend.c" ;

void buff_up(object myself, object target);
void summon_familiar(object myself, object familiar);

int __Buy_here(mixed str){
   object ob;
   string magetype;
   int pgold,cost, success;

   if(!str) return notify_fail("%^BOLD%^Syntax: buy <itemname> or <itemnumber>\n");
   if(!TP->is_class("mage") && !TP->is_class("bard") && !TP->is_class("sorcerer") )
      return notify_fail("Sorry, I sell nothing to non-magi such as yourself.");
   if(member_array(str,({"book","spellbook","spell book"})) != -1){
      if(!TP->query_funds("gold",100)){
         write("%^RED%^You don't have enough money to buy a new spellbook!");
         return 1;
      }
      TP->use_funds("gold",100);
      magetype=MAGIC_D->query_title(TP);
      write("%^CYAN%^Here is a spellbook fit for a "+magetype+" like yourself.");
      new("/d/magic/spellbook")->move(TP);
      return 1;
   }
   if(str == "backup"){
      write("%^RED%^Buy a backup of what?");
      return 1;
   }
   tmpstr = 0;
   if(!sscanf(str,"backup of %s",tmpstr)) sscanf(str,"back up of %s",tmpstr);
   if(tmpstr && tmpstr != ""){
     cost = (int) TP->query_lowest_level();
     cost *= 100;
       if (!newbiep(TP)) {
         TO->force_me("say I'm sorry, but I'll have to charge you the normal rate now, "+TPQCN+".");
         cost = 2000;
      }
     if(!TP->query_funds("gold",cost)){
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
     TP->use_funds("gold",cost);
     write("%^GREEN%^You relinquish your book to "+query_cap_name()+".\n");
     force_me("say I will have your spell book copied in twenty minutes. Come back then to <pickup spell book>");
     ob->save_me(BACKUP_DIR+"/"+TPQN+"_"+query_name()+".backup");
     ob->save_me("/d/magic/spellbook/save_books/"+TPQN+"_"+query_name()+".backup");
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
      TP->use_funds("gold",10);
      write("%^CYAN%^Here is a new components bag.");
      new("/d/magic/comp_bag")->move(TP);
      return 1;
   }
   if(!sscanf(str,"%d",number)){
     if(member_array(str,Available) == -1) return notify_fail("Sorry, I'm not selling any spells of "+str+".\n");
     else number = member_array(str,Available);
   }
   if(number > sizeof(Available)) return notify_fail("There is no spell number %^BOLD%^"+number+".\n");
   cost = spellnames[Available[number]];
   pgold = TP->query_money("gold");
   if(!TP->query_funds("gold",cost)){
     write("%^RED%^You don't have enough money to buy the spell of "+Available[number]+"'s!");
     return 1;
   }
   TP->use_funds("gold",cost);
   write("%^CYAN%^Here is a scroll with the magical text of %^YELLOW%^"+Available[number]+"%^CYAN%^ written upon it.");
   ob = new(SCROLL_PATH);
   ob->set_spell_name(Available[number]);
   if((int)(ob->move(TP))!=MOVE_OK){
      write("You can't carry the scroll, I will drop it on the floor.");
      ob->move(ETP);
      return 1;
   }
   return 1;
}

int __List_here(string str){
   string bigstring;
   int inc,lines,cost;

   lines = to_int(TP->getenv("LINES"));
   lines -= 2;
   if(!str) return notify_fail("Try list spells?\n");
   if(strsrch(str,"spells") == -1) return notify_fail("I don't sell that!\n");
   Available = sort_array(Available,"sort_strings",TO);
   bigstring = LINE;
   for(inc = 0; inc < sizeof(Available);inc++){
      bigstring += sprintf("%3d: ",inc);
      bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n",capitalize(Available[inc]),spellnames[Available[inc]]);
      if(((inc+1)%lines == 0) &&(inc > 1)) bigstring += (LINE + LINE);
   }
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Spell book", 100);
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Components bag", 10);
   if(!newbiep(TP)) cost = 2000;
   if(newbiep(TP)) cost = (int) TP->query_lowest_level() * 100;
   bigstring += sprintf("%%^GREEN%%^%-30s %%^YELLOW%%^%9d %%^RESET%%^%%^CYAN%%^gold\n","Backup", cost);
   bigstring += "Your book's cost here in Offestry will change depending on ";
   bigstring += "your expertise with your magic.\n";
   bigstring += LINE;
   TP->more(explode(bigstring,"\n"));
   return 1;
}

int __Sell_here(string str){
   object ob;
   int level;
   
   if(!str) return 0;
   if(!ob = present(str,TP)) return notify_fail("You don't have that item.\n");
   if(!ob->is_scroll()) return notify_fail("I only buy scrolls.\n");
   if(ob->is_newbie_scroll()) return notify_fail("You will have to sell that to Taribella.\n");
   level = ob->query_spell_level();
   TP->add_money("gold",(level)*50);
   ob->remove();
   write(query_cap_name()+" takes the scroll and hands you some money.");
   tell_room(ETO,query_cap_name()+" takes a scroll from "+TPQCN+" and hands "+TP->query_objective()+" some money.",TP);
   return 1;
}

void create() {
  int i,j,real_useful;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;

  ::create();
  set_property("no attack",1);
  set_property("no bump", 1);
  set_property("strength","spells");
  set("aggressive", 0);
  set_name("Zabeth");
  set_id( ({ "zabeth","Zabeth", "clerk", "shop keeper", "shopkeeper"}) );
  set_short("Zabeth, the mystical scribe");
  set_level(16);
  set_long("%^RESET%^%^CYAN%^Zabeth is an elderly human woman who has dedicated her life to the research of spells and "
"the magic of the weave.  Her %^RESET%^creamy white skin %^CYAN%^has become wrinkled with age and is rather thin, giving "
"it the look of white parchment.  Though not an overly handsome woman, she is saved from being plain by high, graceful "
"cheekbones and %^ORANGE%^warm chestnut brown eyes%^CYAN%^.  Her dark brown hair is streaked with %^BOLD%^%^BLACK%^gray "
"%^RESET%^%^CYAN%^and pulled back into a bun at the base of her neck, though escaped tendrils of hair ring her face and "
"soften her appearance.  She seems to love her work and is never found without a book in her hand and a small %^BLUE%^ink "
"smudge %^CYAN%^on her cheek.\n"+
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
  set_gender("female");
  set_alignment(2);
  set("race", "human");
  set_class("mage");
  set_hd(16,2);
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",8);
  set_stats("charisma",13);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_body_type("human");
  set_guild_level("mage",16);
  set_mlevel("mage",16);
  set_overall_ac(0);
  spells_sold=([ "magic missile":150, "identify":240, "armor":250, "burning hands":250, "chill touch":250, "color spray":150, "light":100, "darkness":100, "sleep":200 ]);
  for(i=0;i<sizeof(spells_sold);i++) spells_sold[keys(spells_sold)[i]] += random(100);
  spells = ({});
  spells_to_sell = ([]);
  for(j = 1;j<20;j++) spells = spells + ({keys(spells_sold)[random(sizeof(keys(spells_sold)))]});
  spells = distinct_array(spells);
  for(j=0;j<sizeof(spells);j++) spells_to_sell[spells[j]] = spells_sold[spells[j]];
  set_spells_sold(spells_to_sell);
  set_spell_chance(90);
  set_spells(({"color spray","hideous laughter","acid arrow","sleep","magic missile","magic missile"}));
  set_size(2);
  set_wielding_limbs( ({ "right hand","left hand" }) );
  ob=new("/d/common/obj/armour/robe.c");
  ob->set_short("%^YELLOW%^A bright-yellow robe%^RESET%^");
  ob->set_long("%^YELLOW%^This is a bright-yellow robe.%^RESET%^");
  ob->move(TO);
  command("wear robe");
  ob=new("/d/newbie/mon/arvanador.c");
  ob->set_property("my_master",TO);
  TO->set_property("my_familiar",ob);
  call_out("summon_familiar",1,TO,ob);
}

void summon_familiar(object myself, object familiar) {
  if ( (!objectp(familiar)) || (!objectp(TO)) || (!objectp(ETO)) ) return;
  familiar->move(environment(myself));
  tell_room(ETO,capitalize(familiar->query_name()) + " flies into the room and lands upon his master's shoulder");
  call_out("buff_up",1,myself,familiar);
  call_out("buff_up",6,myself,myself);
  return;
}

void buff_up(object myself, object target) {
  if ((!objectp(target)) || (!objectp(myself)) || (!objectp(environment(myself)))) return;
  if (!present(target,environment(myself))) return;

  new("/cmds/spells/s/_stoneskin.c")->use_spell(myself,(string)target->query_name(),16,100,"mage");
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return ::__Pickup(str);
    else {
      force_me("say You? There's nothing here for you to pick up.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return __Buy_here(str);
    else {
      force_me("say You? I couldn't let you have any of these scrolls, you wouldn't use them properly.");
      return 1;
    }
}

int __List(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return __List_here(str);
    else {
      force_me("say You? Nope. You wouldn't know how to use these scrolls properly!");
      return 1;
    }
}


/*int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return __Sell_here(str);
    else {
      force_me("say You? I don't by from dabblers. Only those who understand how to handle arcane magic!");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return ::__Help(str);
    else {
      force_me("say You? You need more help than I can provide! My wares would be useless to one such as you.");
      return 1;
    }
}*/
