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
// 	lowered delay for higher levels & cut down spam from praying *Styx* 6/6/06
// generic functions moved to /cmds/mortal in _prepare and _forget. Nienne, 08/10.

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>

#define CLS ESC+"[H"+ESC+"[2J"

inherit ARMOUR;

int forget_spell(string str);
void memorize2(string str, int sl, object play);
void set_holy_symbol(string spell);
void remove_spell(string spell);
void set_owner();
void line();
int add_all();
int add_spell(string str);
string query_owner();
int wisdom_bonus(object player, int level);
void set_diety(string diety);
string query_diety();
void set_sphere(string str);
string query_sphere();
void sort();
void sort_two();private void swap(int i, int j);

nosave mapping spells = ([]);  // Changing this to static to handle removing quest spells -Ares
string *magic, owner,single_class;
int temp;
string diety, sphere_of_influence,myclass;


int check_single_class(object player,string myclass);


int is_holy_symbol() {
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

void set_sphere(string str) {
    sphere_of_influence = str;
}

string query_sphere() {
    return sphere_of_influence;
}

void set_diety(string str) {
    diety = str;
   set_short("holy symbol");
//changed to stop automatic recognition
}

string query_diety() {
    return diety;
}

void create() {
    ::create();
    set_id( ({ "holy symbol","symbol", "true holy symbol"}) );
    set_name("holy symbol");
    set_short("Holy Symbol");
    //set_property("no offer",1);
    set_property("no animate",1);
    //set_property("no steal",1);
/* changing to allow to stay with the corpse so those being raised from dead (bypasses the church giving it back) aren't then stuck without one  *Styx*  8/29/03
    set_property("death remove", 1);
*/
// moving the long set on create to allow for alterobj!
         set_long(
@SYMBOL
%^CYAN%^        This is a Holy Symbol.
%^CYAN%^                                   %^WHITE%^              /|X|\
%^CYAN%^        This is only useful        %^WHITE%^             ||XOX||
%^CYAN%^        to clerics, rangers,       %^WHITE%^              \|X|/
%^CYAN%^        and paladins.              %^WHITE%^      /|X|\----|X|----/|X|\
%^CYAN%^                                   %^WHITE%^     ||XOXXXXXXXXXXXXXXXOX||
%^CYAN%^        < Help Symbol >            %^WHITE%^      \|X|/----|X|---\\|X|/
%^CYAN%^        will show the              %^WHITE%^               |X|
%^CYAN%^        available commands.        %^WHITE%^               |X|
%^CYAN%^                                   %^WHITE%^               |X|
%^CYAN%^        Remember to worship        %^WHITE%^              /|X|\
%^CYAN%^        your Diety at the          %^WHITE%^             ||XOX||
%^CYAN%^        church, often!!            %^WHITE%^              \|X|/
SYMBOL
    );
    set_lore("Holy symbols have long been used to invoke and "+
       "channel the divine powers granted to clerics by their "+
       "patron deities.  It is through these symbols of faith "+
       "and devotion that the powers to cure wounds, heal blindness, "+
       "and summon the divine power for crusades are channeled "+
       "through.  Rangers and Holy Knights are blessed with a "+
       "small portion of divine magic as well, through their holy "+
       "symbols.  Many of lay worshipers in all the faiths have "+
       "taken to wearing holy symbols as well.  Some wear them to "+
       "express their religon.  Others see the wearing of a holy "+
       "symbol as a protection fetish or charm, keeping them safe "+
       "from trouble throughout their days.  Faith is an important "+
       "thing in these lands to all folk, large or small.");
    set_long("Holy Symbol");
    set_type("ring");
    set_limbs(({"neck"}));
    set_weight(1);
}

int valid_has_cleric_spells() {
    if(ETO->is_class("cleric")
    || ETO->is_class("paladin")
    || ETO->is_class("antipaladin")
    || ETO->is_class("ranger")) {
        return 1;
    }
    return 0;
}

void refresh()
{
    spells = ([]);
    add_all();
    return;
}


void init()
{
    ::init();
    if (!living(ETO)) {
        return;
    }
    if (!owner) {
        set_owner();
    }
    if (!query_sphere()) {
        set_sphere((string)(ETO->query_sphere()));
    }
    if (!query_diety()) {
        set_diety((string)(ETO->query_diety()));
    }
}

int add_all() {
    string *all_spells,spellgod,classtype,all,from;
    int x;

    if(catch(get_dir("/cmds/priest/*.c"))) { return 0; }
    all_spells = get_dir("/cmds/priest/*.c");
    for (x=0 ; x < sizeof(all_spells); x++)
    {
		if(catch(new("/cmds/priest/"+all_spells[x]))) { continue; }
        spellgod = ("/cmds/priest/"+all_spells[x])->query_diety();
        if(spellgod == "me" || spellgod == query_diety() || wizardp(ETO))
		{
            //if( ("/cmds/priest/"+all_spells[x])->get_single_class(ETO))
            //{
                if( ("/cmds/priest/"+all_spells[x])->spell_domain_check(ETO))
                {
                    if( ("/cmds/priest/"+all_spells[x])->quest_spells_check(ETO,all_spells[x]))
                    {
                        if( ("/cmds/priest/"+all_spells[x])->is_restricted_to_class(ETO->query_classes()) )
                        {
                        all_spells[x] = replace_string(all_spells[x],"_","",1);
                        all_spells[x] = replace_string(all_spells[x],".c","",1);
                        all_spells[x] = replace_string(all_spells[x],"_"," ");
                        add_spell(all_spells[x]);
                        }
                    }
                }
            //}
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
    if (str != "cleric spells") {
        return 0;
    }
    spells = TP->query_all_memorized("cleric");
    k = keys(spells);
    for (i=0;i<sizeof(k);i++) {
        level = spells[k[i]];
        k2=keys(level);
        for (j=0;j<sizeof(k2);j++) {
            TP->force_me("say I currently have "+k2[j]+" memorized "+level[k2[j]]+" times.");
        }

    }
    return 1;
}

int add_spell(string str) {
    int level,j;
    string str2;

    if (!str) return 1;
    str=lower_case(str);

    if (TP->is_class("ranger"))
        j = 6;
    if (TP->is_class("paladin") || TP->is_class("antipaladin"))
        j = 7;
    if (TP->is_class("cleric"))
        j = 10; // updated for new spell levels

    str2="/cmds/priest/_"+replace_string(str," ","_")+".c";
    if (file_exists(str2)) {
        if (catch(level=str2->query_spell_level()))
            return 0;
        if (level < j)
            set_holy_symbol(str);
    }
    return 1;
}

void set_holy_symbol(string spell) {
    string spell_file;
    int spell_level;

    if (!spells) spells = ([]);
    if (spell) {
        spell_file="/cmds/priest/_"+replace_string(spell," ","_")+".c";
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

int query_holy_symbol(string spell) {
    return spells[spell];
}

int spells(string str) {
    int x, temp1;
    string tmp, Gtype;

    if (!str) str = "by name";
    if (sscanf(str, "by %s", Gtype) != 1) Gtype = "name";

    tmp = ({});
      if((!(TP->is_class("cleric") || TP->is_class("paladin") || TP->is_class("antipaladin") || TP->is_class("ranger") ) || wizardp(TP)) ) {
        tell_object(TP, "This symbol has no meaning to you. ");
        return 1;
    }

    magic = keys(spells);
    tell_object(TP, "\n%^BOLD%^%^CYAN%^This is "+owner+"'s holy symbol.  Its god allows the following spells:");
    line();
    tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell:", 30) + arrange_string("Level:", 10)+"* Memorized:");
    line();

    if (Gtype != "level") sort();
    else sort_two();

    for (x = 0; x < sizeof(magic);x++) {
        if (!temp1 = TP->query_cl_memorized(magic[x]))
            temp1 = 0;
        tmp += ({"%^CYAN%^%^BOLD%^"+arrange_string(magic[x], 30)+"%^RESET%^%^CYAN%^"+arrange_string(spells[magic[x]], 10)+temp1});
    }
    TP->more(tmp);
    line();
    return 1;
}

int pray_spell(string str) {
    int sl, rst, cl, lvadj, num, count, cando;
    string splnm,*known_spells,tmp;

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!(int)TP->query_guild_level("cleric") )
        return notify_fail("Only users with magical abilities may pray for spells!\n");
    if (TP->query_paralyzed())
        return notify_fail(TP->query_paralyze_message());
    if (!str)
        return notify_fail("Pray for what?\n");
    if (query_diety() != (string)ETO->query_diety())
        return notify_fail("This holy symbol did not come from your diety, you cannot pray for spells with it!\n");
//    if (TP->query_property("PKfled") > time())
//        return notify_fail("You are still regaining your wits from your flight from battle!");
    if (TP->query_property("berserked"))
        return notify_fail("Your berserker rage won't give you the peace needed.");
     remove_call_out("flip");
    known_spells = keys(spells);
    tmp = str;
    if(strsrch(tmp," times") != -1) { tmp = tmp[0..(strsrch(tmp," times")-1)]; }

    if(member_array(tmp,known_spells) == -1)
        return notify_fail("You don't know of a spell named "+tmp+" to pray for.\n");


// adding ability to do x number of the same spell *Styx* 6/6/06
    if(sscanf(str,"%s times %d",splnm, num) == 2 || sscanf(str, "%s times", splnm) == 1 )  {
//	tell_object(find_player("styx"), "spellname is "+splnm+" and num is "+num+".");
	str = splnm;
    }
    if(num < 0)
        return notify_fail("You must specify a positive number.  Syntax is <pray spellname> or <pray spellname times # > - use the numeric such as 2.\n");

    if (!sl = query_holy_symbol(str))
        return notify_fail("Your god does not recognize a spell of "+str+"!\n");
    if ( sizeof(TP->query_attackers()) > 0 )
        return notify_fail("You cannot pray for spells while in battle!\n");
    if (TP->query_property("berserked"))
        return tell_object(TP,"Your berserker rage won't give you the peace needed.");

/*
The requirement for blessing a room is out of date and a quality of life issue for clerics. Removing this requirement after discussion with other Imms. No other class has such a requirement. ~Circe~ 5/17/13
    if (sl > 5) {
        if (ETP->query_property("blessed")) {
//adding the below pointerp stuff to holy symbols to
//accomodate the change to holy water ~Circe~ 6/4/08
           if(pointerp(ETP->query_property("blessed"))){
              if(member_array((string)TP->query_diety(),(string*)ETP->query_property("blessed")) == -1) {
                tell_object(TP,"You may not pray in this room for that spell, please bless the room to bring your god's presence to it.");
                return 1;
              }
//if((string)ETP->query_property("blessed") != (string)TP->query_diety()) {
           }else if((string)ETP->query_property("blessed") != (string)TP->query_diety()) {
//end added stuff
                tell_object(TP,"You may not pray in this room for that spell, please bless the room to bring your god's presence to it.");
                return 1;
           }
        } else {
            tell_object(TP,"You may not pray in this room for that spell.  Please bless the room to bring your god's presence to it.");
            return 1;
        }
    }
*/
    rst = TP->can_memorize_cl(str);

    if (rst == TOO_MANY)
        return notify_fail("You have prayed for all of the spells that you are allowed at this level.\n");
    if (rst == SPELL_RESTRICTED)
        return notify_fail("Your god has taken the power of that spell from you.\n");
    if (rst == NOT_WISE)
        return notify_fail("You do not have the wisdom to control that spell.\n");
    if (rst != MEM_OK)
        return notify_fail("You cannot pray for that spell.\n");

/** less spam  *Styx* 6/6/06
**    tell_object(TP, "You kneel before your symbol and your god and start to pray for the spell of "+str+".  This may take awhile.");
**    tell_object(TP, "Hit <RETURN> to cancel memorizing...");
**    tell_room(environment(TP), TPQCN+" kneels before "+TP->query_possessive()+" holy symbol and starts praying to "+TP->query_possessive()+" god.", TP);
**/
    temp = sl * MEMORIZE_DELAY;
// this duration adjustment (same as for spellbooks) added by *Styx* 6/4/06
    cl = TP->query_guild_level("cleric");
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
    tell_object(TP, "%^BOLD%^%^GREEN%^You focus on your holy symbol and begin praying for the spell of "+str+"  ("+num+" attempt(s) - Any action you take will interrupt your praying...)");
    tell_room(environment(TP), TPQCN+" focuses on "+TP->query_possessive()+" holy symbol and begins praying for spells.", TP);

    call_out("flip", 2, str, temp, TP, num);
  // temp above was sl. I changed it to be like the wizards...
  //Garrett.
//    input_to("check_activity", 1);
//    TP->set_paralyzed(temp);
//      TP->setAdminBlock();
       TP->set_property("memorizing",TO);
    return 1;
}

int check_activity(string str) {
    if (remove_call_out("flip") != -1) {
         tell_player(TP, "You interrupt praying to do something else!\n");
//        TP->remove_paralyzed();
        TP->removeAdminBlock();
        return 1;
    }
    return 1;
}

void flip(string str, int sl, object play, int num) {
object obt;
       if (!objectp(obt=play->query_property("memorizing")) && (obt != TO) ) {
//           write(identify(TO)+":"+identify(obt));
           return;
         }
    if (random(8) == 0) {
        tell_object(play,"You feel the power of your god.");
        tell_room(environment(play),play->query_cap_name()+" wavers a second before you.",play);
    }
    temp -= 2;

// more support for multiples of the same spell
    if (temp > 0 && ((int)TP->can_memorize_cl(str) == MEM_OK)) {
// don't wait until the end for all to go in mem. in case they bail from a long set
// tell_object(find_player("styx"), "In flip first try num is "+num+".");
 	if(num > 1 && !random(3)) {
	    play->set_cl_memorized(str, 1);
	    num--;
	}
        call_out("flip", 2, str, sl, play, num);
   } else {
	if(num > 1) {
	  while(num--) {
	    if((int)TP->can_memorize_cl(str) == MEM_OK)
	       play->set_cl_memorized(str, 1);
	  }
        } else {
	    if(num && ((int)TP->can_memorize_cl(str) == MEM_OK))
	       play->set_cl_memorized(str, 1);
	}
        memorize2(str, sl, play);
        temp = 0;
	return 1;
    }
}

void memorize2(string str, int sl, object play) {
//    play->set_cl_memorized(str, 1);
//  has to move into the flip section for multiples
//    TP->remove_paralyzed();
//        play->removeAdminBlock();
      play->remove_property("memorizing");
/** less spam *Styx* 6/6/06
**    tell_room(environment(play),play->query_cap_name()+" finishes praying to "+TP->query_possessive()+" god.",play);
**    tell_object(play, "You have now finished praying for the spell of "+str+".\nHit <RETURN> to continue...");
**/
    tell_room(environment(play),play->query_cap_name()+" completes "+TP->query_possessive()+" prayer.",play);
    tell_object(play, "%^BOLD%^%^GREEN%^You have finished praying. ");
}

int forget_spell(string str) {
    int temp, sl;
    int *in_mind;

    if (!sl = query_holy_symbol(str))
        return notify_fail("That spell does not exist to forget! ["+str+"]\n");

    TP->set_cast_type("priest");

    if (!TP->forget_cl_memorized(str))
        return notify_fail("The spell, \""+str+"\" is not in your memory!\n");
    else
        tell_object(TP, "The spell, \""+str+"\" has been forgotten successfully!");

    return 1;
}

void line() {
    write("%^BLUE%^-----------------------------------------------------------------------");
}


int offer(string str) {
    if (id(str)) {
        tell_object(TP, "%^BOLD%^No offering holy symbols!");
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

//For some reason "help" wasn't doing anything - it looks like it's been taken out of init.
//Fixing up syntax and adding it back. ~Circe~ 5/22/11

int help(string str) {
    int x, calc;
    string tmp;
    int level, *in_mind;

    if (!str)
        return 0;
    if (str != "holy symbol" &&
        str != "holy_symbol" &&
        str != "symbol")
        return 0;

    if ( !interactive(TP) || (!TP->is_class("cleric") && !TP->is_class("paladin") && !TP->is_class("antipaladin")&& !TP->is_class("ranger") && !wizardp(TP)))
        return 0;

    //tell_object(TP, CLS);
    tell_object(TP, "Holy symbols are the gifts of the gods to their followers.");
    tell_object(TP, "With your holy symbol you can:");
//    tell_object(TP, "%^YELLOW%^<pray>%^RESET%^ spellname");
//    tell_object(TP, "- OR - %^YELLOW%^<pray spellname times #> %^GREEN%^example:  <pray light times 3>");
    tell_object(TP, "%^YELLOW%^<prepare classname spellname> %^GREEN%^example: <prepare cleric light>%^RESET%^");
    tell_object(TP, "%^YELLOW%^<prepare classname spellname times #> %^GREEN%^example: <prepare cleric light times 3>%^RESET%^");
    tell_object(TP, "%^YELLOW%^<forget>%^RESET%^ spellname");
    tell_object(TP, "%^YELLOW%^<spells classname>%^RESET%^    Will list spells your god offers");
    tell_object(TP, "%^YELLOW%^<spells classname by level>%^RESET%^    Will list spells your god offers, sorted by spell level");

    if (TP->query_guild_level("cleric")) {
        line();
        in_mind = allocate(10);
        if (TP->is_class("cleric"))
        {
            level = TP->query_class_level("cleric");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "cleric", TP->query_stats("wisdom"));
            in_mind = magic_arsenal_feat(TP,in_mind);
            in_mind = bonus_spell_slots(TP,in_mind);
        }
        if (TP->is_class("paladin"))
        {
            level = TP->query_class_level("paladin");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "paladin", 10);
            in_mind = magic_arsenal_feat(TP,in_mind);
            in_mind = bonus_spell_slots(TP,in_mind);
        }
        if (TP->is_class("antipaladin"))
        {
            level = TP->query_class_level("antipaladin");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "antipaladin", 10);
            in_mind = magic_arsenal_feat(TP,in_mind);
            in_mind = bonus_spell_slots(TP,in_mind);
        }
        if (TP->is_class("ranger"))
        {
            level = TP->query_class_level("ranger");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "ranger", 10);
            in_mind = magic_arsenal_feat(TP,in_mind);
            in_mind = bonus_spell_slots(TP,in_mind);
        }

        if (level < 0 ) level = 0;
        tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell level:", 18)+"Number allowed:      Prepared:     [Your level: "+level+"]");
        line();

        for (x = 0; x < 9;x++) {
            tmp = in_mind[x];
            if(!tmp) tmp = "0";
            tell_object(TP, "%^CYAN%^"+arrange_string((x+1), 18) + arrange_string(tmp,21) + TP->query_num_cl_spells_level(x+1));
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
