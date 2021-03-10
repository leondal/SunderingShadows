//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//      magic_book.c
// fixed up the help and avatar commands so a non-mage avatar can see them, etc.
// *Styx* 10/6/05, last change 2/05
// made memorize delay mitigated by level and cut some of the spam *Styx* 6/4/06
// added ability to memorize multiple copies of a spell from one command *Styx* 6/18/06

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>
#include <schoolspells.h>

#define WIZ_LEV (int)TP->query_class_level("mage")
#define CLS ESC+"[H"+ESC+"[2J"

inherit OBJECT;

nosave string *magic;
mapping spells = ([]);

nosave mapping speccache;

string *mID, bookdesc;
string owner;
int restore, *spells_at_level, *in_mind;


int is_spellbook() {
    return 1;
}

void create() {
    ::create();
    set_id( ({ "book", "bookx", "magic book", "spell book", "spellbook", "tome", "grimoire"}) );
    set_weight(10);
    set_value(0);
    set_name("spell book");
    set_short("A Book");
    set_long("This is a spellbook.");
    add_spell("detect magic");
    add_spell("magic missile");
}

void init() {
    string *mastered;
    int i, masterflag;
    ::init();
    if (!owner)
	{
        set_owner();
	}
    if(stringp(owner))
	{
        if (lower_case(owner) != owner)
		{
            owner = lower_case(owner);
		}
	}
    add_action("memorize_spell", "memorize");
    add_action("look", "look");
    add_action("help", "help");
    add_action("offer","offer");
    add_action("mydesc","setdesc");
    add_action("report_spells","reportspells");
    add_action("remove_spell", "rmspell");
    if((string)TP->query_name() == owner) {
        mastered = ({});
        masterflag = 0;
        if(sizeof(TP->query_mastered_spells("mage"))) {
            mastered += (string)TP->query_mastered_spells("mage");

            for(i = 0;i < sizeof(mastered); i++) {
                if(member_array(mastered[i],keys(spells)) == -1) {
                    set_spellbook(mastered[i]);
                    masterflag = 1;
                }
            }
            if (masterflag) {
                tell_object(TP, "You take your time and scribe mastered spells into your spellbook.");
            }
        }
    }
    validate_book(TP);

    if (avatarp(TP)) add_action("add_spell", "addspell");
    if (avatarp(TP)) add_action("add_all", "addall");
}

void validate_book(object holder) {
    string *allspells;
    string spell;
    allspells = keys(MAGIC_D->query_index("mage"));
    if(!sizeof(allspells))
    {
        tell_object(holder,"Something has gone very wrong with magic, keeping all spells for now.");
        return;
    }
    foreach(spell in keys(spells))
    {
        if(member_array(spell,allspells) == -1)
        {
            map_delete(spells,spell);
            tell_object(holder,"Spellbook vaping non-existant spell: "+spell+".");
        }
    }
}

void cull_non_school_spells(object holder) {
    return;
}

void set_spellbook(string spell) {
    mapping spell_index = MAGIC_D->query_index("mage");

    if (spell)
    {
        if(member_array(spell,keys(spell_index))==-1)
            return;
        spells[spell] = spell_index[spell];
    }
    return 0;
}

string *query_spells() {
    if (!spells || spells == ([ ]) ) return({ });
    else return keys(spells);
}
int get_spell_level(string spell){
      int spell_level;
      set_spellbook(spell);
      spell_level = spells[spell];
      return spell_level;
}

void set_spells(mapping spelllist) {
    if (base_name(PO) != "/std/spell_vend") return;
    spells = spelllist;
}

void remove_spellbook(string spell) {
    remove_spell(spell);
}

int remove_spell(string spell) {
    if (!spell) return 1;
    if (!avatarp(TP))
        if(owner != ETO->query_name())
        {
            write("You can't seem to figure out how to detach pages from this book.");
        }
    map_delete(spells, spell);
    return 1;
}

int query_spellbook(string spell) {
    return spells[spell];
}

int look(string str) {
    object ob;
    string tmp, gtype, pagebuff;
    string filter;
    string * output = ({});
    int x;

    tmp = ({});

    if (!str)
        return 0;

    if(regexp(str,".* by .*"))
        sscanf(str, "%s by %s", str, gtype);
    if(regexp(str,".* of .*"))
        sscanf(str, "%s of %s", str, filter);

    if(!gtype) gtype = "name";

    if (!ob=present(str,TP))
        return 0;
    if ( !(ob == TO) )
        return 0;
    if (!TP->is_class("mage") && !avatarp(TP)) {
        write("This book is nothing more than page after page of words you can't comprehend.");
        return 1;
    }

    magic = keys(spells);

    speccache = filter_mapping(MAGIC_D->query_global_index(),(:member_array($1,$3)!=-1:),magic);

    if(stringp(filter))
    {
        if(regexp(filter,"level [0-9]+"))
        {
            sscanf(filter,"level %s",filter);
            magic = keys(filter_mapping(speccache,(:($2)["levels"]["mage"]==$3:),atoi(filter)));
        }
        else
        {
            magic = keys(filter_mapping(speccache,(:($2)["sphere"][0..3]==$3[0..3]:),filter));
            gtype = "level";
        }
    }
    if (TP->isKnown(owner))
        write("\n%^BOLD%^%^CYAN%^This is $&$"+owner+"$&$'s spell book.  Its pages include the following spells:\n");
    else
        write("\n%^BOLD%^%^CYAN%^You do not realize who this spell book belongs to.  Its pages include the following spells:\n");

    sort();
    switch(gtype)
    {
    case "level":
        sort_by_lev();
        break;
    case "school":
        sort_by_lev();
        sort_by_school();
        break;
    }

    for (x=0;x<sizeof(magic);x++)
    {
        output+=({"%^BOLD%^%^CYAN%^"+arrange_string(magic[x], 24)+"%^RESET%^%^CYAN%^ "+arrange_string(speccache[magic[x]]["sphere"],4)+" "+arrange_string(get_spell_level(magic[x]),2)});
    }

    // Columns interface is documented in _spells.c
    tell_object(TP,auto_format_page(output, TP, 34));

    if (avatarp(TP)) write(
@GARRETT
Avatar functions:
addspell [spellname] - to add a specific spell
rmspell [spellname] - to remove a specific spell
addall - to add all mage spells to your master book for reference
GARRETT
        );
    return 1;
}

int memorize_spell(string str) {
    int sl, rst, temp, cl, lvadj, num;
    string splnm;

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (TP->query_blind())
        return notify_fail("You can't see the words to study the spell.\n");
    if (!(int)TP->query_guild_level("mage"))
        return notify_fail("Only users with magical abilities may memorize spells!\n");
    if (!str)
        return notify_fail("Memorize what?\n");
    if (TP->query_paralyzed())
        return notify_fail(""+(string)TP->query_paralyze_message()+"\n");
    if ( sizeof(TP->query_attackers()) > 0 )
        return notify_fail("You cannot memorize spells while in battle!\n");
    if ((string)TPQN != owner)
        return notify_fail("This is not your spellbook, you cannot memorize spells from it.\n");
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
        return notify_fail("You must specify a positive number.  Syntax is <memorize spellname> or <memorize spellname times # > - use the numeric such as 2.\n");
    if (!sl = query_spellbook(str))
        return notify_fail("You do not have any spell named "+str+" in your book to memorize!\n");

    rst = TP->can_memorize("mage",str);
    if(rst == TOO_STUPID){
        tell_object(TP, "You are not intelligent enough to understand that spell effectively.");
        return 1;
    }
    if(rst == TOO_MANY)
        return notify_fail("You have memorized all of the spells that you are allowed at this level.\n");
    if (rst == SPELL_RESTRICTED)
        return notify_fail("The power to pull that spell from the weave has been taken from you.\n");
    if(rst != MEM_OK)
        return notify_fail("You cannot memorize that spell.\n");

    temp = sl * MEMORIZE_DELAY;
// this adjustment added by *Styx* 6/4/06
    cl = WIZ_LEV;
    if(cl > 9) {
	lvadj = 1000/(WIZ_LEV);
	if(!lvadj)
	   lvadj = 1;   // they say dividing by zero is reserved for god...
	temp = temp - ((temp * 10)/lvadj);
	if(!temp)
	   temp = 1;
    }
// more support for multiple versions of the same spell
    if(!num)  num = 1;
    temp = temp * num;
    tell_object(TP, "%^BOLD%^%^GREEN%^You open your spell book and begin memorizing "+str+".  ("+num+" attempt(s) - Any action you take will interrupt your memorizing...");
    tell_room(ETP, TPQCN+" opens "+TP->QP+" book and starts studying intensely.", TP);
    call_out("flip", 2, str, temp, TP, num);
//    input_to("check_activity", 1);
//    TP->set_property("memorizing",(: TO, "check_activity" :) );
       TP->set_property("memorizing",TO);
//    TP->set_paralyzed(temp);
//    TP->setAdminBlock();
    return 1;
}

int check_activity(string str) {
    if (remove_call_out("flip") != -1) {
        tell_player(TP, "You stop memorizing to do something else!\n");
        //TP->remove_paralyzed();
         TP->removeAdminBlock();
        return 1;
    }
    return 1;
}

void flip(string str, int temp, object play, int num){
object obt;
       if (!objectp(obt=play->query_property("memorizing")) && (obt != TO) ) {
//           write(identify(TO)+":"+identify(obt));
           return;
         }
    if (random(8) == 0) {
        tell_object(play,"You flip to the next page.");
        tell_room(environment(play),play->QCN+" flips to the next page in "+play->QP+" book.", play);
    }
    temp -= 2;
/**************  before multiple copies
*    if (temp > 0)
*        call_out("flip", 2, str, sl, temp);
*    else {
*        memorize2(str, sl);
*        temp = 0;
*        return 1;
*    }
**************/
    if (temp > 0 && ((int)TP->can_memorize("mage",str) == MEM_OK)) {
// don't wait until the end for all to go in mem. in case they bail from a long set
 	if(num > 1 && !random(3)) {
	    play->set_memorized("mage",str, 1);
	    num--;
	}
        call_out("flip", 2, str, temp, play, num);
   } else {
	if(num > 1) {
	  while(num--) {
	    if((int)play->can_memorize("mage",str) == MEM_OK)
	       play->set_memorized("mage",str, 1);
	  }
        } else {
	    if(num && ((int)play->can_memorize("mage",str) == MEM_OK))
	       play->set_memorized("mage",str, 1);
	}
        memorize2(str, temp, play);
        temp = 0;
	return 1;
    }
}

void memorize2(string str, int temp, object play) {
//  has to move into the flip section for multiples
//    TP->set_memorized(str, 1);
    //TP->remove_paralyzed();
//    play->removeAdminBlock();
       play->remove_property("memorizing");
    tell_room(ETP,TPQCN+" finishes studying and closes "+TP->QP+" book.", TP);
//    tell_object(TP, "You have finished memorizing "+str+".  (Hit <RETURN> to continue...)");
    tell_object(play, "%^BOLD%^%^GREEN%^You have finished memorizing "+str+".");
}

int report_spells(string str){
    int i, j;
    mapping spells, level;
    string *k, *k2;
    if (!str) {
        return 0;
    }
    if (str != "mage spells") {
        return 0;
    }
    spells = TP->query_all_memorized("mage");
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

int forget_spell(string str) {
    int sl;

    if (!sl = TP->query_memorized("mage",str))
        return notify_fail("You do not have that spell in your book to forget! ["+str+"]\n");

    TP->set_cast_type("wizard");

    if(!TP->forget_memorized(str))
       return notify_fail("The spell, \""+str+"\" is not in your memory!\n");
    else
       tell_object(TP, "The spell, \""+str+"\" has been forgotten successfully!");

    return 1;
}

int add_spell(string str) {
    if (!str)
        return 1;
    str = lower_case(str);

    if (set_spellbook(str) && avatarp(TP))
        write("Spell added successfully.");
    return 1;
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

    if (!str)
        return 0;
    if (str != "spell book" &&
        str != "spellbook" &&
        str != "book")
        return 0;
    if ( !interactive(TP) || (!TP->is_class("mage") && !avatarp(TP) ))
        return 0;

    //tell_object(TP, CLS);

    write(
"%^BOLD%^%^CYAN%^When you have a spell book, you can%^RESET%^

%^ORANGE%^<look book>%^RESET%^            To see a listing of spells in a spellbook
%^ORANGE%^<look book by level>%^RESET%^   To see a listing of your spells, in order of spell level
%^ORANGE%^<look book by school>%^RESET%^  To see a listing of your spells, in order of spell school
%^ORANGE%^<look book of level LEVEL>%^RESET%^   To see a listing of your spells of a given LEVEL
%^ORANGE%^<look book of SCHOOL>%^RESET%^  To see a listing of your spells of a given SCHOOL
%^ORANGE%^<rmspell %^ULINE%^SPELLNAME%^RESET%^%^ORANGE%^>%^RESET%^    To remove a spell from your book.
%^ORANGE%^<setdesc>%^RESET%^              To set a new book description.

To cast spells use %^ORANGE%^<cast>%^RESET%^.
To prepare spells use %^ORANGE%^<prepare>%^RESET%^.
To remove spells from prepared use %^ORANGE%^<forget>%^RESET%^.
To master spells use %^ORANGE%^<master>%^RESET%^.
To recast buffs use %^ORANGE%^<buff>%^RESET%^.

%^BOLD%^%^WHITE%^A mage %^ULINE%^must%^RESET%^%^BOLD%^%^WHITE%^ have a spellbook to use %^ORANGE%^<prepare>%^RESET%^ command!");

    if (avatarp(TP)) {
        tell_object(TP, "Immortals can also:");
        tell_object(TP, "%^ORANGE%^<addspell SPELLNAME>%^RESET%^\n"
		"%^ORANGE%^<addall>%^RESET%^ - YOUR books only!\n"
	);
    }

    return 1;
}

void line() { write("%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"); }

void set_owner() {
    string *schools, spl, sphere;
    int spellnum;
    object tp;
    tp = ETO;
    /* had interactive(tp) && in this commented out... */ if (TP->is_class("mage")){

        owner = tp->query_name();
        if (spells && sizeof(spells) != 0)
            return 1;
        schools = ({ "abjuration", "conjuration_summoning",
                    "divination", "enchantment_charm",
                    "illusion", "invocation_evocation", "necromancy",
                    "alteration", "elemental"});
        sphere=tp->query_school();
        if (!sphere)
            sphere="invocation_evocation";
        spellnum = member_array(sphere, schools, 0);
        spl = ({"armor","armor","magic missile","sleep",
                    "color spray","magic missile", "chill touch",
                    "burning hands", "burning hands"})[spellnum];
        set_spellbook(spl);
    }
    return 1;
}

int offer(string str) {
    if (id(str)) {
        tell_object(TP, "%^BOLD%^Nobody wants it. If you don't want it drop it!");
        return 1;
    }
    return 0;
}

int add_all() {
    string *all_spells;
    int x;

    all_spells = keys(MAGIC_D->query_index("mage"));
    for(x = 0;x<sizeof(all_spells);x++){
        add_spell(all_spells[x]);
    }
    return 1;
}

string query_owner() {
    return owner;
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

void sort_by_school()
{
    int i, j;

    for (j = 0; j < sizeof(magic); j++) {
        for (i = sizeof(magic) - 1; i > j; i--) {
            if (speccache[magic[i]]["sphere"] < speccache[magic[i - 1]]["sphere"]) {
                swap(i - 1, i);
            }
        }
    }
}

void sort_by_lev()
{
    int i, j;

    for (j = 0; j < sizeof(magic); j++) {
        for (i = sizeof(magic) - 1; i > j; i--) {
            if (spells[magic[i]] < spells[magic[i - 1]]) {
                swap(i - 1, i);
            }
        }
    }
}

private void swap(int i, int j) {
    string tmp;

    tmp = magic[i];
    magic[i]=magic[j];
    magic[j]=tmp;
}

int mydesc(string str) {
   string str2;
   if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
     TP->send_paralyzed_message("info",TP);
     return 1;
   }
   if (avatarp(TP)) {
     TO->set_short(""+str+"%^RESET%^");
     tell_object(TP,"%^WHITE%^%^BOLD%^This spellbook will now appear as:%^RESET%^ "+TO->query_short());
     return 1;
   }
   if ((string)TPQN != owner) {
     tell_object(TP,"This is not your spellbook, you cannot set its appearance.\n");
     return 1;
   }
   if (!str) {
     TO->set_short("A book");
     tell_object(TP,"%^WHITE%^%^BOLD%^Your spellbook will now appear as:%^RESET%^ A book");
     return 1;
   }
   str2 = "/daemon/filters_d"->filter_colors(str);
   if(strsrch(str2,"book") == -1 &&  strsrch(str2,"Book") == -1 &&
      strsrch(str2,"tome") == -1 && strsrch(str2,"Tome") == -1 &&
      strsrch(str2,"grimoire") == -1 && strsrch(str2,"Grimoire") == -1
       ) TO->set_short(""+str+" book%^RESET%^");
   else TO->set_short(""+str+"%^RESET%^");
   tell_object(TP,"%^WHITE%^%^BOLD%^Your spellbook will now appear as:%^RESET%^ "+TO->query_short());
   return 1;
}
