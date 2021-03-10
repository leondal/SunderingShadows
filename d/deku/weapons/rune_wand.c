#include <std.h>

#define stLevSpells ({"_magic_missile","_sleep","_color_spray",\
"_burning_hands"})

#define ndLevSpells ({"_scorcher","_acid_arrow","_ray_of_enfeeblement",\
"_web","_hideous_laughter"})

#define rdLevSpells ({"_fireball","_lightning_bolt","_dispel_magic"})

inherit "/d/common/obj/weapon/club.c";
string spell;
int used;

void create(){
	::create();
	set_name("rune wand");
	set_id(({ "wand", "rune wand", "stick", "simple stick" }));
	set_short("%^BLUE%^A r%^BOLD%^%^RED%^u%^RESET%^%^BLUE%^ne w%^RED%^a%^BLUE%^nd%^RESET%^");
	set_obvious_short("A stick inscribed with strange symbols");
	set_long("This short stick has been carelessly carved from a "+
    "piece of %^BOLD%^%^GREEN%^green oak%^RESET%^.  It is "+
    "nearly a foot long and has been inscribed with very "+
    "strange %^BLUE%^runes%^RESET%^ and %^RED%^symbols%^RESET%^.  "+
    "The %^BLUE%^runes%^RESET%^ and %^RED%^symbols%^RESET%^ are "+
    "impossible to interpret, but a lone inscription circles "+
    "the stick near its thin and frail base.  The end of the stick "+
    "has been slightly rounded, for whatever reason.");

    set_read("Simply 'point wand at foe' to activate its strange "+
    "function");
    set("langage",!random(2) ? "kobold" : "common");
    set_weight(2);
	set_value(1000);
	set_lore("These wands are fairly common amongst renown wizards, "+
    "they are rumored to be easy to create and their function is a "+
    "simple one, yet its effect is unknown to anyone but the one "+
    "who originally imbued the wand with its magic.");
	set_property("enchantment",2+random(2));
    switch(random(3)) {
        case 0:
            spell = stLevSpells[random(sizeof(stLevSpells))];
            set_value(2 * (random(41) * 15));
            break;
        case 1:
            spell = ndLevSpells[random(sizeof(ndLevSpells))];
            set_value(3 * (random(41) * 15));
            break;
        case 2:
            spell = rdLevSpells[random(sizeof(rdLevSpells))];
            set_value(4 * (random(41) * 15));
            break;
    }
}

void init() {
    ::init();
    add_action("point_at","point");
}

void used() {
    write("The wand turns to mush and seeps from your hand!");
    if(!ETO->query_invis()) {
        tell_room(EETO,ETOQCN+"'s wand turns to mush and seeps from "+
        ETO->QP+" hand!%^RESET%^",ETO);
    }
    TO->remove();
}

int point_at(string str) {
    string targ;
    object ob;

    if(!str || used) { return 0; }
    if(sscanf(str,"wand at %s",targ) == 1) {
        if(!query_wielded()) {
            write("You need to wield it first.");
            return 1;
        }
        if(ob = present(targ,EETO)) {
            if(living(ob)) {
                write("You point the wand at "+ob->QCN+ " and wave it "+
                "around quickly!");
                tell_object(ob,ETOQCN + " points "+ETO->QP+" wand "+
                "at you and begins waving it about quickly!");
                tell_room(EETO,ETOQCN+" points "+ETO->QP+" wand "+
                "at "+ob->QCN+" and begins waving it around quickly!",
                ({ob,ETO}));
                ETO->set_paralyzed(3,"%^RED%^You are using the wand!"+
                "%^RESET%^");
                new("/cmds/spells/"+spell[1..1]+"/"+spell+".c")->use_spell(ETO,ob,25 + roll_dice(1, 20),50,"mage");
                used = 1;
                used();
                return 1;
            }
            if(!living(ob)) {
                write("That is not a living target!");
                return 1;
            }
        }
        write("You do not see that target here!");
        return 1;
    }
    return 0;
}
