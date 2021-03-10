//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//      magic_book.c

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>

#define WIZ_LEV TP->is_class("mage")?(int)TP->query_guild_level("mage"):(int)TP->query_guild_level("bard")
#define CLS ESC+"[H"+ESC+"[2J"

inherit OBJECT;

void set_spellbook(string spell);
string *query_spells();
void set_spells(mapping spelllist);
void remove_spellbook(string spell);
int remove_spell(string spell);
int query_spellbook(string spell);
int look(string str);
int memorize_spell(string str);
int check_activity(string str);
void flip(string str, int sl);
void memorize2(string str, int sl);
int forget_spell(string str);
int add_spell(string str);
int help(string str);
void line();
void set_owner();
int offer(string str);
int add_all();
string query_owner();
void sort();
void sort_two();
private void swap(int i, int j);

mapping spells = ([]);
string *magic, *mID, bookdesc;
string owner;
int restore, temp, *spells_at_level, *in_mind;


int is_spellbook() {
    return 1;
}

void create() {
    ::create();
    set_id( ({ "book", "bookx", "magic book", "spell book", "spellbook"}) );
    set_weight(10);
    set_value(0);
    set_name("spell book");
    set_short("A Book");
    set_long("This is a spellbook.");
}

void init() {
    ::init();
    if (!owner)
        set_owner();
    if (lower_case(owner) != owner)
        owner = lower_case(owner);
    add_action("memorize_spell", "memorize");
    add_action("forget_spell", "forget");
//    add_action("copy", "copy");
    add_action("look", "look");
    add_action("help", "help");
    add_action("offer","offer");
    if (wizardp(TP)) add_action("remove_spell", "rmspell");
    if (avatarp(TP)) add_action("add_spell", "addspell");
    if (avatarp(TP)) add_action("add_all", "addall");
}

void set_spellbook(string spell) {
    string a_buggy_spell;
    string spell_file;
    int spell_level;
    if (spell) {
        spell_file="/cmds/wizard/_"+replace_string(spell," ","_")+".c";
        if (file_exists(spell_file)) {
            if (a_buggy_spell = catch(spell_level=spell_file->query_spell_level()))
	      write(a_buggy_spell + ": "+ spell_file );
            if (!spell_level) return;
            if (!spell) return;
            spells[spell] = spell_level;
            return 1;
        }
        return 0;
    }
    return 0;
}

string *query_spells() {
    if (!spells || spells == ([ ]) )
        return({ });
    else
        return keys(spells);
}
int get_spell_level(string spell){
      int spell_level;
     set_spellbook(spell);
       spell_level = spells[spell];
      return spell_level;
}

void set_spells(mapping spelllist) {
    if (base_name(PO) != "/std/spell_vend")
        return;
    spells = spelllist;
}

void remove_spellbook(string spell) {
    remove_spell(spell);
}

int remove_spell(string spell) {
    if (!spell) return 1;
    map_delete(spells, spell);
    return 1;
}

int query_spellbook(string spell) {
    return spells[spell];
}

int look(string str) {
    object ob;
    int x;
    string tmp, gtype, temp1;

    tmp = ({});

    if (!str)
        return 0;

    sscanf(str, "%s by %s", str, gtype);
    if(!gtype) gtype = "name";

    if (!ob=present(str,TP))
        return 0;
    if ( !(ob == TO) )
        return 0;
    if ( !interactive(TP) && (!TP->is_class("mage") && !TP->is_class("bard") || !wizardp(TP))) {
        write("This book is nothing more than page after page of words you can't comprehend.");
        return 1;
    }

    magic = keys(spells);
    write("\n%^BOLD%^%^CYAN%^This is "+capitalize(owner)+"'s spell book.  Its pages include the following spells:\n");
    line();
    write("%^MAGENTA%^"+arrange_string("Spell:", 30) +arrange_string("Level:", 10)+arrange_string("* Memorized:", 15)+"Level of Proficiency");
    line();

    if(gtype != "level") sort();
    else sort_two();

    for (x=0;x<sizeof(magic);x++) {
        if (!temp1 = ""+TP->query_memorized(magic[x]))
            temp1 = ""+0;
          tmp += ({"%^CYAN%^%^BOLD%^"+arrange_string(magic[x], 30)+"%^RESET%^%^CYAN%^"+arrange_string(get_spell_level(magic[x]),10)+arrange_string(temp1,15)+TP->query_spell_prof_level(magic[x])});
    }

    TP->more(tmp);
    line();
    return 1;
}

int memorize_spell(string str) {
    int sl, rst;
    object ownr;


    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if (TP->query_blind())
        return notify_fail("You can't see the words to study the spell.\n");
    if (!(int)TP->query_guild_level("mage") && !(int)TP->query_guild_level("bard") )
        return notify_fail("Only users with magical abilities may memorize spells!\n");
    if (!str)
        return notify_fail("Memorize what?\n");
    if (TP->query_paralyzed())
        return notify_fail(""+(string)TP->query_paralyze_message()+"\n");
    if (!sl = query_spellbook(str))
        return notify_fail("You do not have any spell named "+str+" in your book to memorize!\n");
    if ( sizeof(TP->query_attackers()) > 0 )
        return notify_fail("You cannot memorize spells while in battle!\n");
    if ((string)TPQN != owner)
        return notify_fail("This is not your spellbook, you cannot memorize spells from it.\n");
    if (TP->query_property("berserked"))
        return tell_object(TP,"Your berserker rage won't give you the peace needed.");


    rst = TP->can_memorize(str);

    if(rst == TOO_STUPID){
        tell_object(TP, "You are not intelligent enough to understand that spell effectively.");
        return 1;
    }
    if(rst == TOO_MANY)
        return notify_fail("You have memorized all of the spells that you are  allowed at this level.\n");
    if (rst == SPELL_RESTRICTED)
        return notify_fail("The power to pull that spell from the weave has been taken from you.\n");
    if(rst != MEM_OK)
        return notify_fail("You cannot memorize that spell.\n");

    tell_object(TP, "You sit down, open your spell book, and begin to memorize the spell of "+str+".  This may take awhile.");
    tell_object(TP, "Hit <RETURN> to cancel memorizing...");
    tell_room(environment(TP), TPQCN+" sits down and opens "+TP->query_possessive()+" book and starts studying it intensely.", TP);
    temp = sl * MEMORIZE_DELAY;
    call_out("flip", 2, str, sl);
    input_to("check_activity", 1);
    TP->set_paralyzed(temp);
    return 1;
}

int check_activity(string str) {
    if (remove_call_out("flip") != -1) {
        tell_player(TP, "You stop memorizing to do something else!\n");
        TP->remove_paralyzed();
        return 1;
    }
    return 1;
}

void flip(string str, int sl) {
    if (random(8) == 0) {
        tell_object(TP,"You flip to the next page.");
        tell_room(environment(TP),TPQCN+" flips to the next page in "+TP->query_possessive()+" book.", TP);
    }
    temp -= 2;
    if (temp > 0)
        call_out("flip", 2, str, sl);
    else {
        memorize2(str, sl);
        temp = 0;
        return 1;
    }
}

void memorize2(string str, int sl) {
    TP->set_memorized(str, 1);
    TP->remove_paralyzed();
    tell_room(environment(TP),TPQCN+" closes "+TP->query_possessive()+" book, and stands up.", TP);
    tell_object(TP, "You have now finished memorizing the spell of "+str+".");
    tell_object(TP, "Hit <RETURN> to continue...");
}

int forget_spell(string str) {
    int temp, sl, allowed_sl;
    object ownr;
    mapping memorized;
    int *in_mind;

    if (!sl = TP-> query_memorized(str))
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
    seteuid(UID_LOG);
       log_file("addspell",capitalize(TPQN)+" added "+str+" to "+owner+"'s spellbook.\n");
    seteuid(getuid());
    if (set_spellbook(str))
        write("Spell added successfully.");
    return 1;
}

int help(string str) {
    int x, calc;
    int *in_mind;

    if (!str)
        return 0;
    if (str != "spell book" &&
        str != "spellbook" &&
        str != "book")
        return 0;
    if ( !interactive(TP) || (!TP->is_class("bard") && !TP->is_class("mage") && !wizardp(TP) ))
        return 0;

    tell_object(TP, CLS);
    tell_object(TP, "Spell books are the prized possessions of the magi.");
    tell_object(TP, "When you have a spell book, you can:");
    tell_object(TP, "%^YELLOW%^<memorize>%^RESET%^ spells");
    tell_object(TP, "%^YELLOW%^<forget>%^RESET%^ spells");
    tell_object(TP, "%^YELLOW%^<look book>%^RESET%^ To see a listing of your spells");
    tell_object(TP, "%^YELLOW%^<look book by level>%^RESET%^ To see a listing of your spells, in order of spell level");

    if (wizardp(TP)) {
        tell_object(TP, "%^YELLOW%^<rmspell>%^RESET%^ spells");
        tell_object(TP, "%^YELLOW%^<addspell>%^RESET%^ spells");
    }

    if (WIZ_LEV) {
        line();
        if (TP->is_class("mage"))
            tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell level:", 18)+"Number allowed:    [Your level: "+TP->query_guild_level("mage")+"]");
        else if (TP->is_class("bard"))
            tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell level:", 18)+"Number allowed:    [Your level: "+TP->query_guild_level("bard")+"]");
        line();

        in_mind = allocate(10);
        if(TP->is_class("mage"))
            in_mind = (int)WIZ_CALCS->query_max_spell_array(WIZ_LEV, "mage");
        else
            in_mind = (int)WIZ_CALCS->query_max_spell_array(WIZ_LEV, "bard");

        for (x = 0; x < 9;x++)
            tell_object(TP, "%^CYAN%^"+arrange_string((x+1), 18) + in_mind[x]);

        line();
    }
    return 1;
}

void line() {
    tell_object(TP, "%^BLUE%^--------------------------------------------------------------------------------");
}

void set_owner() {
    string *schools, spl, sphere;
    int spellnum;
    object tp;
    tp = ETO;
    if ( interactive(tp) &&(TP->is_class("mage") || TP->is_class("bard")) ) {
        owner = tp->query_name();
        if (spells && sizeof(spells) != 0)
            return 1;
        schools = ({ "abjuration", "conjuration_summoning",
                   "greater divination", "enchantment_charm",
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
        tell_object(TP, "%^BOLD%^No offering spell books, if you don't want it sell it!");
        return 1;
    }
    return 0;
}

int add_all() {
    string *all_spells;
    int x;

    all_spells = keys((mixed *)MAGIC_D->query_mage_index());
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
void sort_two() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (spells[magic[i]] < spells[magic[i-1]]) {
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
