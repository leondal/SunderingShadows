#include <std.h>
#include <spellsbylevel.h>
#include <daemons.h>
inherit OBJECT;

string spell, * readpassed;
mapping readfailed;

#define SCRL_CLASSES ({"bard", "mage", "cleric", "druid", "inquisitor", "paladin", "ranger", "magus"})
#define DEBUG 0

/**
 * @file
 * @brief Magic scroll
 */

int level, usable;
int is_newbie;

int is_scroll()
{
    return 1;
}

void create()
{
    ::create();
    set_name("scroll");
    set_id(({ "scrollx", "scroll" }));
    set_long((: TO, "long_desc" :));
    set_short("a scroll");
    set_spell(1);
    set_weight(1);
    set_value(10);
    set_read("You should <use scroll> with spell arguments.");
}

void init()
{
    ::init();
    set_long((: TO, "long_desc" :));
    if (ETO == TP && interactive(TP)) {
        if (wizardp(TP)) {
            add_action("set_scroll", "set");
        }
        if (TP->is_class("mage") || avatarp(TP)) {
            add_action("transcribe", "transcribe");
        }
        add_action("use_scroll", "use");
        add_action("wash_scroll", "wash");
        if (!level) {
            set_clevel(TP->query_level() > CHARACTER_LEVEL_CAP ? CHARACTER_LEVEL_CAP : TP->query_level());
        }
        set("lore", "%^BOLD%^%^ORANGE%^This is a scroll of " + query_spell_name() + " of " + query_clevel() + "'th circle.");
        set("lore difficulty", TO->query_spell_level() + 15);
    }
}

string long_desc()
{
    string long;
    if (!objectp(TP)) {
        return ("This is a scroll with some undecipherable writing on it.");
    }
    if (base_name(TO) == "/d/magic/safe_scroll" ||
        base_name(TO) == "/d/magic/newbie_scroll" &&
        (member_array(spell, keys(MAGIC_D->query_index("mage"))) != -1)) {
        long = "%^ORANGE%^This is a magic scroll of " + spell + ".
You can <use> it directly in order to properly study and learn more about the effects of the spell. It cannot be transcribed.%^RESET%^";
        return long;
    }
    return ("%^ORANGE%^This is a magic scroll of " + spell + ". You can <transcribe> it into your spell book or <use> it directly.%^RESET%^");
}

string query_short()
{
    string color;

    if (MAGIC_D->query_spell_level("mage", spell)) {
        color = "%^ORANGE%^";
    }else {
        color = "%^WHITE%^";
    }

    if (!objectp(TP)) {
        return ("%^RESET%^" + color + "scr%^BOLD%^o%^RESET%^" + color + "ll%^RESET%^");
    }
    return ("%^RESET%^" + color + "scr%^BOLD%^o%^RESET%^" + color + "ll of " + spell + "%^RESET%^");
}

varargs void set_spell(int mylevel, myclevel)
{
    mylevel = mylevel - 2 + roll_dice(1, 4);

    myclevel ? set_av_spell(mylevel, myclevel) : set_av_spell(mylevel);
}

varargs void set_av_spell(int mylevel, int myclevel)
{
    string * rclass;
    string * rspell;

    mylevel = mylevel > 9?9:mylevel;
    mylevel = mylevel < 1?1:mylevel;

    rclass = SCRL_CLASSES[random(sizeof(SCRL_CLASSES))];
    rspell = MAGIC_D->query_random_spell(rclass, rspell);
    if (!rspell) {
        set_spell_name("magic missile");
    } else {
        set_spell_name(rspell);
    }

    if (!myclevel && objectp(ETO)) {
        if (ETO->is_living() && ETO->query_level()) {
            set_clevel(ETO->query_level() + roll_dice(1, 8));
        }
    } else {
        set_clevel(myclevel);
    }
}

// compatibility function
set_spell_level(int l)
{
    level = l;
}

set_clevel(int l)
{
    level = l;
}

void set_scroll(string str)
{
    string scroll_id, scroll_spell;
    if (!str) {
        return 0;
    }
    if (sscanf(str, "%s to %s", scroll_id, scroll_spell) != 2) {
        return 0;
    }
    if (present(scroll_id, TP) != TO) {
        return 0;
    }
    set_spell_name(scroll_spell);
    write("Scroll altered.");
}

void set_spell_name(string str)
{
    //////////////////////////////////////////////////////////////////////
    //This section added by Lujke May 31/05 to prevent scrolls
    // retaining the name of their old spell when the spell name is changed.
    ///////////////////////////////////////////////////////////////////////
    string* old_id_list, tmp;
    int x;
    old_id_list = query_id();
    old_id_list -= ({ spell, "" });
    set_id(old_id_list);
    // End of added section //
    spell = str;
    if (sscanf(spell, "%s%d", tmp, x) == 2) {
        tmp = tmp + consolidate_number(x);
        add_id(tmp);
    }
    add_id(spell);
    set_long("This is a magic scroll of " + spell + ".  You can " +
             "<transcribe> it into your spell book or <use> it directly.");
    return 1;
}

string query_spell_name()
{
    return spell;
}

int transcribe(string str)
{
    object book;
    int prev;
    int after;
    if (TP->light_blind(0)) {
        return notify_fail("You cannot see well enough to read this.\n");
    }
    if (TP->query_blind()) {
        return notify_fail("How could you transcribe something you can't see??\n");
    }
    if (!stringp(str)) {
        return notify_fail("Transcribe what?\n");
    }
    if (present(str, TP) != TO) {
        return 0;
    }
    book = present("bookx", TP);
    if (!book) {
        notify_fail("You don't have a spell book to transcribe the spell into!\n");
        return 0;
    }
    if (member_array(spell, keys(MAGIC_D->query_index("mage"))) == -1) {
        notify_fail("You can only transcribe arcane spells");
    }
    write("%^ORANGE%^You carefully file " + spell + " into your spellbook.\n");
    book->set_spellbook(spell);
    TO->remove();
    return 1;
}

int use_scroll(string str)
{
    int lev, back, num, valid, rogue_clevel;
    int stat;
    string caster, targ, what, what2, * classes;
    string * scroll_classes, *player_classes;
    int lowest_spell_level, highest_mental_stat;
    object ob;

    caster = TP->query_name();
    if (!str) {
        return notify_fail("Use what?\n");
    }
    if (!(sscanf(str, "%s on %s", what, targ) == 2)) {
        if (!(sscanf(str, "%s at %s", what, targ) == 2)) {
            if (!(sscanf(str, "%s to %s", what, targ) == 2)) {
                what = str;
            }
        }
    }

    if (targ == "me") {
        targ = TP->query_name();
    }

    if (!present(what, TP)) {
        return 0;
    }

    if (present(what, TP) != TO) {
        return 0;
    }

    player_classes = this_player()->query_classes();
    scroll_classes = keys(MAGIC_D->query_index_row(spell)["levels"]);
    lowest_spell_level = min(values(MAGIC_D->query_index_row(spell)["levels"]));
    highest_mental_stat = max(({this_player()->query_stats("intelligence"), this_player()->query_stats("wisdom"), this_player()->query_stats("charisma") })) - 10;

    if (this_player()->query_property("shapeshifted")) {
        tell_object(TP, "You can't read scrolls while shapeshifted.");
        return 1;
    }

    if (TP->query_bound() || TP->query_paralyzed() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }

    if (TP->query_gagged()) {
        tell_object(TP, "You can't speak so you can't read the scroll aloud!");
        return 1;
    }
    
    valid = 0;
    rogue_clevel = 0;
    
    foreach(string cls in player_classes)
    {
        string temp;
        
        temp = cls;
        
        if(temp == "sorcerer")
            temp = "mage";
        
        if(temp == "oracle")
            temp = "cleric";
        
        //tell_object(this_player(), "%^MAGENTA%^BOLD%^Checking class : " + temp);
        
        if(member_array(temp, scroll_classes) >= 0)
            valid = 1;
    }
    
    if(this_player()->is_class("cypher"))
        valid = 1;
    
    if(lowest_spell_level > this_player()->query_level() / 2)
        valid = 0;
    
    lev = TO->query_clevel();
    
    //tell_object(this_player(), "%^YELLOW%^VALID CLASS = %^RESET%^" + valid);
    
    if(!valid)
    {   
        //Thieves/bards can use a different roll based on class levels
        rogue_clevel = this_player()->query_prestige_level("thief") + this_player()->query_prestige_level("bard");
        
        if(FEATS_D->usable_feat(this_player(), "use magic device") && rogue_clevel > this_player()->query_skill("spellcraft"))
        {
            int roll = roll_dice(1, 20);
            int DC = this_object()->query_clevel() + lowest_spell_level;

            //rogue_clevel = this_player()->query_prestige_level("thief") + this_player()->query_prestige_level("bard");
            
            if(rogue_clevel / 2 < lowest_spell_level)
            {
                tell_object(this_player(), "The scroll is too complex to decipher.");
                return;
            }
            
            if(this_player()->is_class("bard"))
                rogue_clevel += BONUS_D->query_stat_bonus(this_player(), "charisma");
            else
                rogue_clevel += BONUS_D->query_stat_bonus(this_player(), "intelligence");
            
            roll += rogue_clevel;
            
            if((roll < DC || roll == 1) && roll != 20)
            {
                //this_player()->add_cooldown("use scroll", 180);
                tell_object(this_player(), "You fail to properly recite the scroll and mess up the spell! The scroll evaporates in your hands!");
                remove();
                return 1;
            }
            
            lev = rogue_clevel;
        }
        //Other users have to pass a check to try to cast off-class. Kind of difficult, for a reason.
        else if(highest_mental_stat < lowest_spell_level)
        {
            int DC = 20 + lowest_spell_level;
            int roll = roll_dice(1, 20) + (highest_mental_stat / 2) + (this_player()->query_skill("spellcraft") / 10);
            
            if((roll < DC || roll == 1) && roll != 20)
            {
                //this_player()->add_cooldown("use scroll", 180);
                tell_object(this_player(), "You fail to properly recite the scroll and mess up the spell! The scroll evaporates in your hands!");
                remove();
                return 1;
            }
        }
    }
    
    //Thieves use their rogue_level as a cap
    //Others use their spellcraft as a cap
    if(rogue_clevel)
        lev = min( ({ lev, rogue_clevel }) );
    else
        lev = min( ({ lev, this_player()->query_skill("spellcraft") + highest_mental_stat / 2 }) );

    if (FEATS_D->usable_feat(TP, "enhance scroll")) {
        lev = TP->query_prestige_level(TP->query("base_class"));
        lev += TP->query_property("empowered");
    }

    if (lev < 1) {
        lev = 1;
    }

    if (TP->query_casting()) {
        tell_object(TP, "You are already casting a spell");
        return 1;
    }

    ob = new("/cmds/spells/" + spell[0..0] + "/_" + replace_string(spell, " ", "_"));
    if (ob->query_target_required() && !targ) {
        return notify_fail("You need to specify a target to use that spell!\n");
    }
    TP->set_property("spell_casting", ob);
    ob->use_spell(TP, targ, lev);

    if (FEATS_D->usable_feat(TP, "insightful scroll")) {
        //if (roll_dice(1, 100) < ((TP->query_stats("intelligence") + 30) - 2 * query_spell_level())) {
        //if(roll_dice(1, 100) < this_player()->query_stats("intelligence") + 30)
        if(roll_dice(1, 100) < (30 + this_player()->query_skill("spellcraft") / 2))
        {
            tell_object(TP, "%^RESET%^%^MAGENTA%^Your %^BOLD%^%^CYAN%^k%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^owledge%^RESET%^%^MAGENTA%^ of the %^BOLD%^%^CYAN%^Wea%^RESET%^%^CYAN%^v%^CYAN%^e%^MAGENTA%^ is so %^CYAN%^pe%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^f%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^ct%^MAGENTA%^ that you %^BOLD%^%^CYAN%^preserve%^RESET%^%^MAGENTA%^ the scroll!%^RESET%^");
            return 1;
        }
    }

    remove();
    return 1;
}

int wash_scroll(string args)
{
    if (TO != present(args, TP)) {
        return 0;
    }

    tell_object(TP,"%^BOLD%^%^WHITE%^You quickly wash the magic away from the scroll and get a parchment.");
    tell_room(ETP, "%^BOLD%^%^WHITE%^" + TP->QCN + " clears magic from a scroll.", TP);
    new("/d/tharis/obj/parchment")->move(TP);
    TO->remove();
}

int query_spell_level()
{
    return max(map_array(SCRL_CLASSES, (: MAGIC_D->query_spell_level($1, spell) :)));
}

int query_scroll_level()
{
    return level;
}

int query_clevel()
{
    return level;
}

int do_back_fire(object myuser)
{
    return 0;
}

int query_value()
{
    int level = query_spell_level();

    return (level * level) * 100;
}

int query_usable()
{
    return usable;
}

//Added by Saide to test to make sure the query_readable_by() function is working
//correctly - 3/18/2007
void set_usable(int x)
{
    usable = x;
}

void set_passed(string charname)
{
    if (!readpassed) {
        readpassed = ({});
    }
    if (!readfailed) {
        readfailed = ([]);
    }
    if (member_array(charname, readpassed) == -1) {
        readpassed += ({ charname });
    }
    if (readfailed[charname]) {
        map_delete(readfailed, charname);
    }
}

string* query_passed()
{
    return readpassed;
}

mapping query_failed()
{
    return readfailed;
}

string query_scroll_spell()
{
    return spell;
}

void set_is_newbie(int x)
{
    is_newbie = x;
}

int query_is_newbie()
{
    return is_newbie;
}
