#include <std.h>
#include <clock.h>
#include <rooms.h>
#include <new_exp_table.h>
#include <objects.h>
#include <daemons.h>

mixed* genoutput(object targ)
{
    mixed* output = ({});
    {
        string race_var;
        object shape;
        race_var = capitalize(targ->query_race());
        if (targ->query("subrace")) {
            if (strsrch(targ->query("subrace"), targ->query_race()) < 0) {
                race_var = capitalize(targ->query("subrace")) + " " + race_var;
            } else {
                race_var = capitalize(targ->query("subrace"));
            }
        }

        if (targ->query_acquired_template()) {
            race_var = capitalize(targ->query_acquired_template() + " " + race_var);
        }

        if (objectp(shape = TP->query_property("shapeshifted"))) {
            race_var = (string)shape->query_shape_race();
            race_var = capitalize(race_var);
        }
        output += ({ ({ "Race", "%^BOLD%^%^CYAN%^" + capitalize(race_var) }) });
    }

    output += ({ ({ "Gender", "%^BOLD%^%^BLUE%^" + capitalize(targ->query_gender()) }) });

#define AL_COLOR ({ "%^BOLD%^%^YELLOW%^", "%^BOLD%^%^WHITE%^", "%^WHITE%^", "%^BOLD%^%^BLUE%^", "%^BLUE%^", "%^CYAN%^", "%^ORANGE%^", "%^BOLD%^%^RED%^", "%^RED%^" })
    output += ({ ({ "Alignment", AL_COLOR[targ->query_alignment() - 1] + capitalize(targ->query_al_title(targ->query_alignment())) }) });

    output += ({ ({ "Class", "%^BOLD%^%^MAGENTA%^" + implode(targ->query_classes(), "/") }) });

    {
        string* classes = targ->query_classes();
        string cl;
        string* clvls = ({});

        foreach(cl in classes)
        {
            clvls += ({ "" + targ->query_class_level(cl) });
        }

        output += ({ ({ "Level", "%^BOLD%^%^GREEN%^" + implode(clvls, "/") + " (%^RESET%^" + targ->query_adjusted_character_level() + "%^BOLD%^%^GREEN%^)" + (targ->query("scaledlevel") ? "%^RED%^(scaled)%^RESET%^" : "") }) });
    }

    if (targ->query_adjusted_character_level() < 100) {
        output += ({ ({ "Exp to Next", "%^BOLD%^%^WHITE%^" + english_number(total_exp_for_level(targ->query_adjusted_character_level() + 1) - targ->query_exp()) }) });
    }
    if (mapp(targ->query_XP_tax()["improvement"])) {
        output += ({ ({ "Exp Tax", "%^BOLD%^%^CYAN%^" + english_number(targ->query_XP_tax()["improvement"]["amount"]) }) });
    }
    output += ({ ({ "Exp", "%^BOLD%^%^CYAN%^" + english_number(targ->query_exp()) }) });


    output += ({ ({ "Armor Class", "%^BOLD%^%^WHITE%^" + BONUS_D->effective_ac(targ) + " base + " + BONUS_D->ac_bonus(targ, targ) + " dex" }) });
    output += ({ ({ "Base Hit", BONUS_D->new_bab(1, targ) }) });

    if (stringp(targ->query_diety())) {
        output += ({ ({ "Deity", "%^BOLD%^%^MAGENTA%^" + capitalize(targ->query_diety()) }) });
    }
    if (stringp(targ->query_sphere())) {
        output += ({ ({ "Sphere", "%^BOLD%^%^BLUE%^" + targ->query_sphere() }) });
    }
    if (targ->is_class("sorcerer")) {
        if (stringp(targ->query_bloodline())) {
            output += ({ ({ "Bloodline", "%^BOLD%^%^RED%^" + capitalize(targ->query_bloodline()) }) });
        }
    }
    if (targ->is_class("oracle")) {
        if (stringp(targ->query_mystery())) {
            output += ({ ({ "Mystery", "%^BOLD%^%^CYAN%^" + targ->query_mystery() }) });
        }
    }
    if (targ->is_class("warlock")) {
        if (stringp(targ->query("warlock heritage"))) {
            output += ({ ({ "Heritage", "%^BOLD%^%^MAGENTA%^" + capitalize(targ->query("warlock heritage")) }) });
        }
    }
    if (targ->is_class("mage") ||
        targ->is_class("archmage")) {
        if (targ->query_school() && targ->query_opposing_school()) {
            output += ({ ({ "Schools", "%^BOLD%^%^CYAN%^" + sprintf("%.4s", targ->query_school()) + "%^WHITE%^ vs%^CYAN%^ " + sprintf("%.4s", targ->query_opposing_school()) }) });
        }else {
            output += ({ ({ "Schools", "%^BOLD%^%^CYAN%^universalist" }) });
        }
    }
    if (targ->is_class("psion")) {
        if (stringp(targ->query_discipline())) {
            output += ({ ({ "Discipline", "%^BOLD%^%^CYAN%^" + targ->query_discipline() }) });
        }
    }
    if (targ->is_class("fighter")) {
        if (stringp(targ->query_fighter_style())) {
            output += ({ ({ "Fighter Style", "%^BOLD%^%^CYAN%^" + targ->query_fighter_style() }) });
        }
    }
    if (targ->is_class("monk")) {
        if (stringp(targ->query("monk way"))) {
            output += ({ ({ "Monk Way", "%^BOLD%^%^CYAN%^" + capitalize(targ->query("monk way")) }) });
        }
    }
    if(targ->is_class("ranger")) {
        output += ({ ({ "Favored Enemy", "%^BOLD%^CYAN%^" + implode(targ->query_favored_enemies(), "/") }) });
        output += ({ ({ "Favored Terrain", "%^BOLD%^CYAN%^" + implode(targ->query_favored_terrains(), "/") }) });
    }

    if (sizeof(targ->query_divine_domain())) {
        output += ({ ({ "Divine Domain", "%^BOLD%^%^WHITE%^" + implode(targ->query_divine_domain(), "/") }) });
    }

    output += ({ ({ "Play Time", "%^BOLD%^%^WHITE%^" + parse_time(targ->query_age()) }) });

    output += ({ ({ "Age", "%^BOLD%^" + targ->query_real_age() + " %^CYAN%^(" + targ->query_real_age_cat() + ")" }) });
    output += ({ ({ "Height", "%^YELLOW%^" + targ->query_player_height() + " %^MAGENTA%^inches" }) });
    output += ({ ({ "Weight", "%^YELLOW%^" + targ->query_player_weight() + " %^MAGENTA%^lbs" }) });
    output += ({ ({ "Body type", "%^YELLOW%^" + targ->query_body_type() }) });
    output += ({ ({ "Hair Color", "%^BOLD%^" + targ->query_hair_color() }) });
    output += ({ ({ "Eye Color", "%^BOLD%^" + targ->query_eye_color() }) });
    return output;
}

int cmd_score(string args)
{
    mixed* output = ({}), oline;
    object targ;

    if (TP->query_race() == "unborn") {
        return notify_fail("You are in creation!
Use <review> to review you choices or <press button> to start the process.\n");
    }

    targ = TP;

    if (args) {
        if (args && avatarp(TP)) {
            if (!(targ = find_player(args))) {
                return notify_fail("That person is not available for scoring.\n");
            }
        }
    }

    output = genoutput(targ) + "/cmds/mortal/_hp"->genoutput(targ);

    write("%^RESET%^%^GREEN%^--=%^BOLD%^<%^WHITE%^ " + targ->query_title() + " %^BOLD%^%^GREEN%^>%^RESET%^%^GREEN%^=--%^RESET%^");

    {
        string * obuff;

        obuff = map_array(output, (:arrange_string("%^BOLD%^%^GREEN%^ " + arrange_string($1[0] + " %^BOLD%^%^BLACK%^--------------", 14) + "%^RESET%^%^GREEN%^ : %^RESET%^" + $1[1], $2):), 34);

        tell_object(TP, auto_format_page(obuff, TP, 36));
    }

    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

score - show your characters score sheet

%^CYAN%^SYNOPSIS%^RESET%^

score
Avatars: score [%^ORANGE%^%^ULINE%^TARGET%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command gives you overview of your character, listing many various facts about them.

Avatars and above can specify target other than themselves.

%^CYAN%^SEE ALSO%^RESET%^

hp, money, stats, biography, inventory, eq, flag, who
");
}
