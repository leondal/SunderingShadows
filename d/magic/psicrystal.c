//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//		converted to holy_symbol in adlib manner for clerical use
//		Tristan@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//		General Cleric
//      magic_book.c
//      holy_symbol.c
//      took god names out of the prayer ending message 12/26/04 Tsera
//      changed symbols to show rangers spells 1-5, and paladins/anti's 1-6 -Tsera
//      changed symbols to query for spell class to allow spells to be 
//      set for one type of class 3/22/05 -Tsera
//      Made wearable by Circe 4/10/05 after approval from T
//      Adapted by Circe for use with psionics 7/14/05
// 	lowered delay for higher levels *Styx* 6/6/06
//      added memorizing multiple copies from one command *Styx* 6/18/06
// generic functions moved to /cmds/mortal in _prepare and _forget. Nienne, 08/10.

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>

#define CLS ESC+"[H"+ESC+"[2J"

inherit ARMOUR;

int forget_spell(string str);
void memorize2(string str, object play);
void set_psicrystal(string spell);
void remove_spell(string spell);
void set_owner();
void line();
int add_all();
int add_spell(string str);
string query_owner();
int intelligence_bonus(object player, int level);
void set_discipline(string str);
string query_discipline();
void sort();
void sort_two();
private void swap(int i, int j);

mapping spells = ([]);
string *magic, owner;
int temp, descflag, longflag;
string mydiscipline;

int is_psicrystal() {
    return 1;
}

void set_owner() {
    //if (interactive(ETO)) {
        owner = ETO->query_name();
    //}
    return;
}

string query_owner() {
    return owner;
}

void set_discipline(string str) {
    mydiscipline = str;
}

string query_discipline() {
    return mydiscipline;
}

void create() {
    ::create();
    set_id(({"crystal","psicrystal","focus"}));
    set_name("psicrystal");
    set_short("a shimmering crystal");
    set_property("no animate",1);
    set_lore("Psycristals are the focii of psions, those rare humans "+
       "who have learned the secrets of unlocking their mind and "+
       "using its full potential.  Psionic powers are different from "+
       "arcane magic, coming from within oneself rather than from the "+
       "Weave tended by Mystra.  Magi often view psions as odd "+
       "at best, though some have tried to work with psions to gain "+
       "more of an understanding of their abilities.  Likewise, many "+
       "psions view magi as weak, relying on the whim of another.  The "+
       "psion is tied to his psicrystal, however, and needs it to "+
       "manifest his powers.");
    set_long("This roughly-cut crystal sparkles in the light, "+
       "hanging from a twined silk cord.  The crystal has been "+
       "left partially in the rough, but it seems to resonate "+
       "with an intrinsic energy that pulses within your mind.");
    descflag = 0;
    longflag = 0;
    set_type("ring");
    set_limbs(({"neck"}));
    set_weight(1);
}

int valid_has_psion_spells() {
    if(ETO->is_class("psion") || ETO->is_class("psywarrior")) {
        return 1;
    }
    return 0;
}

void init() {
    ::init();
    if(!living(ETO)) return;
    if (!owner) set_owner();
    if (!query_discipline()) set_discipline((string)(ETO->query_discipline()));
    if (avatarp(TP)) add_action("resetdesc","resetpsidesc");
    if(((string)ETO->query_name() == owner || 
    (string)ETO->QCN == owner)
    && valid_has_psion_spells()) {
//        add_action("spells", "powers");
//        add_action("pray_spell", "focus");
//        add_action("forget_spell", "forget");
        add_action("help", "help");
//        add_action("report_spells","report");
        add_action("mydesc","setpsidesc");
        add_action("mylong","setpsilong");
//        add_all();
    }
}

int add_all() {
    string *all_spells,spelldisc,classtype,all,from;
    int x;

    all_spells = get_dir("/cmds/psionics/*.c");
    for (x=0 ; x < sizeof(all_spells); x++) {
        spelldisc = ("/cmds/psionics/"+all_spells[x])->query_discipline();
        if(spelldisc == "me" || spelldisc == query_discipline() || wizardp(ETO)) {
            if( ("/cmds/psionics/"+all_spells[x])->is_restricted_to_class(ETO->query_classes()) ){
            all_spells[x] = replace_string(all_spells[x],"_","",1);
            all_spells[x] = replace_string(all_spells[x],".c","",1);
            all_spells[x] = replace_string(all_spells[x],"_"," ");
            add_spell(all_spells[x]);
            }
        }
    }
    return 1;
}

int report_spells(string str){
    int i, j;
    mapping spells, level;
    string *k, *k2;
    if (!str) {
        return 0;
    }
    if (str != "psion powers") {
        return 0;
    }
    spells = TP->query_all_psi_memorized();
    k = keys(spells);
    for (i=0;i<sizeof(k);i++) {
        level = spells[k[i]];
        k2=keys(level);
        for (j=0;j<sizeof(k2);j++) {
            TP->force_me("say I currently have "+k2[j]+" prepared "+level[k2[j]]+" times.");
        }
    }
    return 1;
}

int add_spell(string str) {
    int level,j;
    string str2;

    if (!str) return 1;
    str=lower_case(str);
    
    if (TP->is_class("psion"))
        j = 10;

    str2="/cmds/psionics/_"+replace_string(str," ","_")+".c";
    if (file_exists(str2)) {
        if (catch(level=str2->query_spell_level()))
            return 0;
        if (level < j)
            set_psicrystal(str);
    }
    return 1;
}

void set_psicrystal(string spell) {
    string spell_file;
    int spell_level;

    if (!spells) spells = ([]);
    if (spell) {
        spell_file="/cmds/psionics/_"+replace_string(spell," ","_")+".c";
        if (file_exists(spell_file)) {
            spell_level=spell_file->query_spell_level();
            if (!spell_level) return;
            if (!spell) return;
            spells[spell] = spell_level;
            return 1;
        }
        return 0;
    }
    return 0;
}

int remove_spell(string spell) {
    if (!spell) return 1;
    map_delete(spells, spell);
    return 1;
}

int query_psicrystal(string spell) {
    return spells[spell];
}

int spells(string str) {
    int x, temp1;
    string tmp, Gtype;

    if (!str) str = "by name";
    if (sscanf(str, "by %s", Gtype) != 1) Gtype = "name";

    tmp = ({});
      if((!(TP->is_class("psion") ) || wizardp(TP)) ) {
        tell_object(TP, "This crystal has no meaning to you. ");
        return 1;
    }

    magic = keys(spells);
    tell_object(TP, "\n%^BOLD%^%^CYAN%^This is "+capitalize(owner)+"'s "+
       "psicrystal.  Its owner can manifest the following powers:");
    line();
    tell_object(TP, "%^MAGENTA%^"+arrange_string("Power:", 30) + arrange_string("Level:", 10)+"* Memorized:");
    line();

    if (Gtype != "level") sort();
    else sort_two();

    for (x = 0; x < sizeof(magic);x++) {
        if (!temp1 = TP->query_psi_memorized(magic[x]))
            temp1 = 0;
        tmp += ({"%^CYAN%^%^BOLD%^"+arrange_string(magic[x], 30)+"%^RESET%^%^CYAN%^"+arrange_string(spells[magic[x]], 10)+temp1});
    }
    TP->more(tmp);
    line();
    return 1;
}

int pray_spell(string str) {
    int sl, rst, cl, lvadj, num;
    string splnm;

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!(int)TP->query_guild_level("psion") )
        return notify_fail("Only users with intrinsic psionic "+
           "energy may focus for powers!\n");
    if (TP->query_paralyzed())
        return notify_fail(TP->query_paralyze_message());
    if (!str)
        return notify_fail("Focus for what?\n");
    if ( sizeof(TP->query_attackers()) > 0 )
        return notify_fail("You cannot focus for powers while in battle!\n");
    if (TP->query_property("berserked"))
        return notify_fail("Your berserker rage won't give you the peace needed.");
//    if (TP->query_property("PKfled") > time())
//        return notify_fail("You are still calming down from your flight from battle!");
    remove_call_out("flip");
// adding ability to do x number of the same spell *Styx* 6/6/06
    if(sscanf(str,"%s times %d",splnm, num) == 2 || sscanf(str, "%s times", splnm) == 1 )  {
	str = splnm;
    }	
    if(num < 0)
        return notify_fail("You must specify a positive number.  Syntax is <focus spellname> or <focus spellname times # > - use the numeric such as 2.\n");

    if (!sl = query_psicrystal(str))
        return notify_fail("Your mind cannot manifest any such power!\n");

    rst = TP->can_memorize_psi(str);

    if (rst == TOO_MANY)
        return notify_fail("You have focused for all the powers your "+
           "mind can hold at this level.\n");
    if (rst == SPELL_RESTRICTED)
        return notify_fail("Your mind has lost the ability to "+
           "manifest that power.\n");
    if (rst == NOT_SMART)
        return notify_fail("Your mind is not strong enough to retain that power.\n");
    if (rst != MEM_OK)
        return notify_fail("You cannot focus for that power.\n");

    temp = sl * MEMORIZE_DELAY;
// this duration adjustment (same as for spellbooks) added by *Styx* 6/4/06
    cl = TP->query_guild_level("psion");
    if(cl > 9) {
	lvadj = 1000/(cl);
	if(!lvadj)
	   lvadj = 1;   // they say dividing by zero is reserved for god...
	temp = temp - ((temp * 10)/lvadj);
	if(!temp)
	   temp = 1;
    }
    if(!num)  num = 1;
    temp = temp * num;
    tell_object(TP, "%^BOLD%^%^GREEN%^You take your psicrystal in hand and close your "+
       "eyes, focusing on the mysteries of the power "+str+".  "+
       "You may need some time to grasp this power.");
    tell_object(TP, "%^BOLD%^("+num+" attempt(s) - Any action you take will interrupt your focusing.)%^RESET%^");
    tell_room(ETP, TPQCN+" takes "+TP->QP+" psicrystal in hand and closes "+
       ""+TP->QP+" eyes, focusing silently.", TP);

    call_out("flip", 2, str, temp, TP, num);
//    input_to("check_activity", 1);
//    TP->setAdminBlock();
     TP->set_property("memorizing",TO);
    return 1;        
}

int check_activity(string str) {
    if (remove_call_out("flip") != -1) {
         tell_player(TP, "You interrupt focusing to do something else!\n");
        TP->removeAdminBlock();
        return 1;
    }
    return 1;
}

void flip(string str, int temp, object play, int num) {
object obt;
       if (!objectp(obt=play->query_property("memorizing")) && (obt != TO) ) {
//           write(identify(TO)+":"+identify(obt));
           return;
         }
    if (random(8) == 0) {
        tell_object(play,"The intricacies of the power swirl within your mind.");
        tell_room(environment(play),play->QCN+"'s head bows as "+
           ""+play->QS+" sways before you.",play);
    }
    temp -= 2;

/********** before being able to do multiple copies *Styx* 6/18/06
*    if (temp > 0)
*        call_out("flip", 2, str, temp, play);
*    else {
*        memorize2(str, temp, play);
*        temp = 0;
*        return 1;
*    }
***********/
// more support for multiples of the same spell
    if (temp > 0 && ((int)play->can_memorize_psi(str) == MEM_OK)) {
// don't wait until the end for all to go in mem. in case they bail from a long set
 	if(num > 1 && !random(3)) { 
	    play->set_psi_memorized(str, 1);
	    num--;
	}
        call_out("flip", 2, str, temp, play, num);
   } else {
	if(num > 1) {
	  while(num--) {
	    if((int)play->can_memorize_psi(str) == MEM_OK)
	       play->set_psi_memorized(str, 1);
	  }
        } else {
	    if(num && ((int)play->can_memorize_psi(str) == MEM_OK))
	       play->set_psi_memorized(str, 1);
	}
        memorize2(str, play);
        temp = 0;
	return 1;
    }
}

void memorize2(string str, object play) {
//  has to move into the flip section for multiples
//    play->set_psi_memorized(str, 1);
//    play->removeAdminBlock();
    play->remove_property("memorizing");      
    tell_room(environment(play),play->QCN+" finishes focusing and "+
        "opens "+play->QP+" eyes.",play);
    tell_object(play, "%^BOLD%^%^GREEN%^You have finished focusing for the power "+
        "of "+str+".");
}

int forget_spell(string str) {
    int temp, sl;
    int *in_mind;

    if (!sl = query_psicrystal(str))
        return notify_fail("That spell does not exist to forget! ["+str+"]\n");

    TP->set_cast_type("psionics");

    if (!TP->forget_psi_memorized(str))
        return notify_fail("The power \""+str+"\" is not in your memory!\n");
    else
        tell_object(TP, "The power \""+str+"\" has been forgotten successfully!");

    return 1;
}

void line() {
    write("%^BLUE%^-----------------------------------------------------------------------");
}


int offer(string str) {
    if (id(str)) {
        tell_object(TP, "%^BOLD%^No offering psicrystals!");
        return 1;
    }
    return 0;
}

int *magic_arsenal_feat(object ob, int *spells)
{
    int i;

    if(FEATS_D->usable_feat(ob,"magic arsenal"))
    {
        for(i=0;i<sizeof(spells);i++)
        {
            if(!spells[i]) { continue; }
            spells[i] += 2;
        }
    }
    return spells;
}


int *bonus_spell_slots(object ob, int *spells)
{
    int i,extra;

    if(!objectp(ob)) { return spells; }

    extra = (int)ob->query_property("bonus_spell_slots");
    if(!intp(extra) || !extra) { return spells; }

    for(i=0;i<sizeof(spells);i++)
    {
        if(!spells[i]) { continue; }
        spells[i] += extra;
        if(spells[i] < 0) { spells[i] = 0; }
    }

    return spells;
}




int help(string str) {
    int x, calc;
    string tmp;
    int level, *in_mind;

    if (!str)
        return 0;
    if (str != "psicrystal" &&
        str != "crystal")
        return 0;

    if ( !interactive(TP) || !TP->is_class("psion") || !TP->is_class("psywarrior")) { if(!wizardp(TP)) { return 0; } }
        

    //tell_object(TP, CLS);
    if(avatarp(TP)) tell_object(TP,"You may <resetpsidesc> to allow a "+
       "player to reset the description on his psicrystal.  NOTE: This "+
       "will reset both the long and the short descriptions.");
    tell_object(TP, "Each psicrystal is attuned to its owner's mind "+
       "and serves as a focal point for his powers.");
    tell_object(TP, "With your psicrystal you can:");
//    tell_object(TP, "%^YELLOW%^<focus>%^RESET%^ powername");
    tell_object(TP, "%^YELLOW%^<prepare>%^RESET%^ psion powername");
//    tell_object(TP, "- OR - %^YELLOW%^<focus powername times #> %^GREEN%^example:  <focus light times 3>");
    tell_object(TP, "%^YELLOW%^<prepare>%^RESET%^ psion powername times #");
    tell_object(TP, "%^YELLOW%^<forget>%^RESET%^ powers");
//    tell_object(TP, "%^YELLOW%^<powers>%^RESET%^    Will list the powers your mind offers.");
    tell_object(TP, "%^YELLOW%^<spells> %^RESET%^psion - Will list the powers your mind offers.");
//    tell_object(TP, "%^YELLOW%^<powers by level>%^RESET%^    Will list the powers your mind offers, sorted by power level.");
    tell_object(TP, "%^YELLOW%^<spells> %^RESET%^psion by level - Will list the powers your mind offers, sorted by level.");
    tell_object(TP,"%^BOLD%^%^MAGENTA%^You may also <setpsidesc> to "+
       "give your psicrystal a new short description and <setpsilong> "+
       "to give it a new long description.");


    if (TP->query_guild_level("psion")) {
        line();
        in_mind = allocate(10);
        if (TP->is_class("psion"))
        {
            level = TP->query_class_level("psion");
            in_mind = (int)PSION_CALCS->query_max_spell_array(level, "psion", TP->query_stats("intelligence"));
            in_mind = magic_arsenal_feat(TP,in_mind);
            in_mind = bonus_spell_slots(TP,in_mind);

        }

        if (level < 0 ) level = 0;
        tell_object(TP, "%^MAGENTA%^"+arrange_string("Power level:", 18)+"Number allowed:      Prepared:     [Your level: "+level+"]");
        line();
        
        for (x = 0; x < 9;x++) {
            tmp = in_mind[x];
            if(!tmp) tmp = "0";
            tell_object(TP, "%^CYAN%^"+arrange_string((x+1), 18) + arrange_string(tmp,21) + TP->query_num_psi_spells_level(x+1));
        }

        line();
    }
    return 1;
}

void sort() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (magic[i] < magic[i-1]) {
                swap(i-1,i);
            }
        }
}

private void swap(int i, int j) {
    string tmp;

    tmp = magic[i];
    magic[i]=magic[j];
    magic[j]=tmp;
}

void sort_two() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (spells[magic[i]] < spells[magic[i-1]]) {
                swap(i-1,i);
            }
        }
}

int mydesc(string str) {
   string str2;
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
   }
   if (avatarp(TP)) {
      if (!str) {
        TO->set_short("a shimmering crystal");
        tell_object(TP,"%^WHITE%^%^BOLD%^Your psicrystal will now appear as:%^RESET%^ a shimmering crystal");
        return 1;
     }
     TO->set_short(""+str+"%^RESET%^");
     tell_object(TP,"%^YELLOW%^This psicrystal will now appear as:%^RESET%^ "+TO->query_short());
     return 1;
   }
   if ((string)TPQN != owner) {
     tell_object(TP,"This is not your psicrystal.  You cannot set its appearance.\n");
     return 1;
   }
   if (descflag) {
     tell_object(TP,"You have already set this psicrystal's appearance!\n");
     return 1;
   }
   if (!str) {
     TO->set_short("a shimmering crystal");
     tell_object(TP,"%^WHITE%^%^BOLD%^Your psicrystal will now appear as:%^RESET%^ a shimmering crystal");
     return 1;
   }
   str2 = "/daemon/filters_d"->filter_colors(str);
   if(strsrch(str2,"crystal") == -1 && strsrch(str2,"Crystal") == -1) TO->set_short(""+str+" crystal%^RESET%^");
   else TO->set_short(""+str+"%^RESET%^");
   tell_object(TP,"%^WHITE%^%^BOLD%^Your psicrystal will now appear as:%^RESET%^ "+TO->query_short());
   descflag = 1;
   return 1;
}

int mylong(string str) {
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
   }
   if (avatarp(TP)) {
      if (!str) {
        tell_object(TP,"You didn't input any information!  Your psicrystal's "+
           "description will remain the same.");
        return 1;
      }
     TO->set_long(""+str+"%^RESET%^");
     tell_object(TP,"%^YELLOW%^This psicrystal will now appear as:%^RESET%^ "+TO->query_long());
     return 1;
   }
   if ((string)TPQN != owner) {
     tell_object(TP,"This is not your psicrystal.  You cannot set its long description.\n");
     return 1;
   }
   if (longflag) {
     tell_object(TP,"You have already set this psicrystal's long description!\n");
     return 1;
   }
   if (!str) {
     tell_object(TP,"You didn't input any information!  Your psicrystal's "+
        "description will remain the same.");
     return 1;
   }
   TO->set_long(""+str+"%^RESET%^");
   tell_object(TP,"%^WHITE%^%^BOLD%^Your psicrystal will now appear as:%^RESET%^ "+TO->query_long());
   longflag = 1;
   return 1;
}

int resetdesc() {
   descflag = 0;
   longflag = 0;
  if (avatarp(TP)) write("This psicrystal can be redescribed now.");
return 1;
}
