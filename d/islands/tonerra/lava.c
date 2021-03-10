//lava tubes inheritable
//Heavily modified by dinji on 2/11/09 after modifications by Styx & Garrett
//rewritten to get rid of obsolete code and hopefully stop some persistent bugs -Ares 08/14/09

#include <std.h>
#include <daemons.h>
#include "/d/islands/tonerra/areadefs.h"

inherit CROOM;

string what;
object room;
int flag,party,trap,getmobs;

string * features = ({
        "Molten rock creates stalagmite formation here.",
            "There are several tiles forming a patch of ancient road here.",
            "There is a pool of %^BOLD%^%^RED%^magma%^RESET%^%^RED%^ on the side of the pathway.",
            "Humanoid %^RESET%^%^WHITE%^bones%^RESET%^%^RED%^ form a pile on the side.",
            "It is very hot out here, almost deadly hot.",
            "The ground slowly shakes in tone with rumbling of magma streams down below.",
            "The sulfurous odor of lava permeates the air, with puffs of smoke and ash clouding your vision.",
            "A ruddy red light of small rivulets of molten lava flowing through channels in the floor illuminate the darkness of the cavernous tubes.",
            "Large boulder lies on the side, ready to be shot out of the crater.",
    });


void pick_critters()
{
    string *str,dir;
    object *temp,ob;

    switch(random(50))
    {
    case 0..3:

        set_monsters(({OBJ+"lavastream"}),({1}));
        break;

    case 4..10:

        if(trap)
        {
            str = (string *)TO->query_exits();
            if(!sizeof(str)) break;
            dir = str[random(sizeof(str))];
            set_trap_functions(({dir}),({"newt"}),({dir}));
            add_item("alcoves","There seems to be something hidden in the rocky alcove toward the "+dir+".");
            what = "newt&"+dir;
            trap = 0;
            break;
        }
        else
        {
            set_monsters(({MON+"magman"}),({roll_dice(1,2)}));
            break;
        }

    case 11..16:

        set_monsters(({MON+"magman"}),({1}));
        break;

    case 17..23:

        set_monsters(({MON+"harginn"}),({roll_dice(1,2)}));
        break;

    case 24..49:

        set_monsters(({MON+"fnewt"}),({roll_dice(3,3)}));
        monster_party(25); // CROOM can automatically do this now
    }
}


void create()
{
    if(random(3)) getmobs = 1;
    if(getmobs) pick_critters();
    party = 1;
    trap = 1;
    ::create();
    set_indoors(1);
    set_terrain(NAT_TUNNEL);
    set_travel(FOOT_PATH);
    set_short("%^BOLD%^%^BLACK%^L%^RESET%^%^RED%^a%^RED%^v%^RED%^a %^RED%^T%^BOLD%^%^BLACK%^ube%^RESET%^%^RED%^s%^RESET%^");
    set_long(query_short() + "\n%^RED%^Molten rock forms these pathways deep below the surface. When the volcano is active, these tubes carry molten magma towards the surface, to the sea."+make_fdesc() + "\n");
    set_listen("default","%^RED%^The lava flowing under your feet makes a strange buzzing sound.");
    set_smell("default","%^BLACK%^%^BOLD%^You smell the burning %^RED%^l%^RED%^a%^BOLD%^%^BLACK%^va%^RESET%^%^RED%^ and %^BOLD%^%^BLACK%^hot %^RESET%^%^RED%^r%^BOLD%^%^BLACK%^ocks.%^RESET%^");
    set_property("no teleport",1);
    set_property("used sticks",1);
}

void reset()
{
    if(getmobs)
    {
        if(!has_mobs())
        {
            if(mons)  mons = ([]);
            pick_critters();
        }
    }

    ::reset();
}


int newt()
{
    string verb;
    object ob,*inven2,*inven,tmp,targ;
    int i,j;

    verb = query_verb();
    toggle_trap(verb); // putting this up here before the verb changes..  they can be fickle -Ares

    if(TP->query_true_invis()) return 0;
    if(!objectp(TP)) return 0;

    tell_room(TO,"%^BOLD%^As "+TPQCN+" wanders "+verb+" the rock around "+TP->query_objective()+" "
        "come alive and spears fly through the air.",TP);
    tell_object(TP,"%^BOLD%^As you walk "+verb+" the rock around you come alive and spears "
        "fly through the air!");

    inven = all_living(TO);
    inven = filter_array(inven, "is_non_immortal_player",FILTERS_D);

    for(i=0;i<roll_dice(1,4);i++)
    {
        ob=new(MON+"fnewt");
        ob->move(TO);
        for(j=0;j<sizeof(inven);j++)
        {
            if(!objectp(ob)) { continue; }
            if(!objectp(inven[j])) { continue; }
            ob->kill_ob(inven[j],1);
        }
    }

    tmp = new("/d/common/obj/weapon/spear_lg");
    tmp->set_property("enchantment",3);

    for(i=0;i<roll_dice(3,4);i++)
    {
        if(!objectp(ob)) { continue; }
        if(!objectp(TP)) { continue; }

        if(i < 3) { targ = TP; }
        else
        {
            if(!sizeof(inven)) { continue; }
            if(!objectp(targ = inven[random(sizeof(inven))])) { continue; }
        }
        if(!objectp(targ)) { continue; }

        if(ob->Thaco(1,targ,tmp) < random(20) + 4)
        {
            tell_object(targ,"You are hit with a spear!");
            tell_room(TO,targ->QCN+" is hit with a spear!",targ);
            targ->add_attacker(ob);
            targ->continue_attack();
            ob->do_hits(targ, tmp, "torso");
            if(objectp(targ) && objectp(ob)) { targ->remove_attacker(ob); }
        }
    }

    tell_room(TO,"%^BOLD%^%^BLUE%^Mounted firenewts appear from the rocks and "
        "the hot steam and attack!");
    return 1;
}

string query_long(string str)
{
    string hold,one,two;

    hold = ::query_long(str);
    if(!what) return hold;

    sscanf(what,"%s&%s",one,two);
    if(!one || !trapped(two)) return hold;

    switch (one)
    {
        case "newt":
        hold += "You hear a low breathing from the alcoves in the rock.";
        return hold;
        break;
    }
    return hold;
}

string make_fdesc()
{
    int* featurearr;
    int i;
    string fdesc;
    fdesc = "";
    featurearr = distinct_array(
        map_array(
            explode(
                crypt(file_name(TO),
                      "$1$")[4..6],
                ""),
            (: atoi(sprintf("%d", $1[0])) % $2:),
            sizeof(features)));
    for (i = 0; i < sizeof(featurearr); ++i) {
        fdesc += " " + features[featurearr[i]];
    }
    return fdesc;
}
