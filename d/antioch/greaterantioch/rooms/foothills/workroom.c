#include <std.h>
#include <daemons.h>

//inherit "/std/player_storage_room.c";
// my ftp worked!
inherit CROOM;

int going_wild;
object *wild_monsters=({});

int go_wild(object room);
int world_gone_wild_tm(string str);
int wild(string str);
void kill_stuff();

void create()
{
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("smithy",1);
        set_property("no starve",1);
        set_terrain(RUINS);
        set_travel(PAVED_ROAD);
        set_short("%^RED%^Ares Workroom%^RESET%^");
        set_long(
        "%^RED%^A sparsely furnished workroom%^RESET%^\n"+
        "%^BOLD%^This room contains a large table with a contour map "+
        "of various places of the world.  There are several chairs "+
        "arranged around the table, and various sketches on "+
        "the walls%^RESET%^\n\n"
                );
        
        set_smell("default","You smell nothing.");
        set_listen("default","You hear nothing.");
        set_items((["chairs" : "The plush leather chairs look quite comfortable",
                    "sketches" : "Sketches of the anatomy of various creatures "+
                    "and blueprints for weapons and armor adorn the walls.",
                 ]));
        set_exits(([
        "cage" : "/realms/ares/cage",
			"box": "/realms/ares/cage",
        ]));
        set_property("blessed","ares");

        //query_property("fill waterskin")

        set_property("fill waterskin", 1);

}


void init()
{
    object obj,obj2;

    if(objectp(TP))
    {
        if(userp(TP))
        {
            if(objectp(obj = find_player("ares")))
            {
                obj2 = present("tsera",TO);
                if(obj != TP)
                {
                    tell_object(obj,"%^RESET%^%^B_BLUE%^%^WHITE%^"+capitalize(TP->query_true_name())+" enters "
                        "your workroom.%^RESET%^");
                }
                if(objectp(obj2))
                {
                    if(TP != obj2)
                    {
                        tell_object(obj2,"%^RESET%^%^B_BLUE%^%^WHITE%^"+capitalize(TP->query_true_name())+ " enters "
                            "Ares' Workroom.%^RESET%^");
                    }
                }
            }
        }
    }

    if((string)TP->query_true_name() == "hades")
    {
        TP->move("/realms/hades/workroom.c");
        return;
    }
    
    ::init();
    add_action("equipment", "equipment");
    add_action("test_func","test");
    add_action("truce","truce");
    add_action("wild","go_wild");
}



int truce(string str) 
{
    object *inv;
    int i;

    tell_room(ETP,""+TP->QCN+" calls a truce.\n");

    inv = all_inventory(ETP);

    for(i=0; i<sizeof(inv); i++) 
    {
        if(!living(inv[i])) continue;
        inv[i]->cease_all_attacks();
    }
    return 1;
}





void equipment()
{
    tell_object(TP,"%^BOLD%^%^GREEN%^Moving to equipment generator.%^RESET%^");
    tell_room(ETP, "%^BOLD%^%^GREEN%^"+TPQCN+" fades into the shadows.%^RESET%^",TP); 
    TP->move("/realms/ares/equipment_generator.c");
    TP->force_me("look");
    return 1;
}

void reset() 
{
  object ob;
  ::reset();
  if (!objectp(present(getuid(TO)+"_board"))) 
  {
     ob = new("std/bboard");
     ob->set_name(getuid(TO)+"board");
     ob->set_id( ({ "board", getuid(TO)+"_board", "my board" }) );
     ob->set_board_id(geteuid(TO)+"_board");
     ob->set("short", "%^BOLD%^%^WHITE%^Ares' Board of Usefull(less) things%^RESET%^");
     ob->set("long", "Blah blah, oh look! more Blah!!\n");
     ob->set_max_posts(50);
     ob->set_ooc_board(1);
     ob->set_restricted_read();
     ob->set_location(base_name(TO));
     ob->move(TO);
     ob->set_property("no steal",1);
     // Garrett has no idea why that is there. He thinks it is a mistake.
  }
}



int test_func(string str)
{

    if(!catch(call_other("/realms/ares/brokedummy.c","???")))
    {
        tell_object(TP,"There was not an error.");
        return 1;
    }

    tell_object(TP,"There was an error.");
    return 1;
}

















int is_correct_room(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(!obj->is_room()) { return 0; }
    if(obj->query_property("indoors")) { return 0; }
    if(strsrch(base_name(obj),"newbie") != -1) { return 0; }
    if(strsrch(base_name(obj),"realms") != -1) { return 0; }
    if(strsrch(base_name(obj),"void") != -1) { return 0; }
    if(strsrch(base_name(obj),"freezer") != -1) { return 0; }
    if(strsrch(base_name(obj),"/shadowgate/") != -1) { return 0; }
    return 1;
}



string get_critter()
{
    string *critters = ({ 
        "/d/magic/mon/plant",
        "/d/magic/mon/gen_snake",
        "/d/magic/mon/rat",
        "/d/magic/mon/bat",
        "/d/magic/mon/giantrat",
        "/d/magic/mon/giantbat",
        "/d/magic/mon/gscorpion",
        "/d/magic/mon/hyena",
        "/d/magic/mon/spider",
        "/d/magic/mon/wolf",
    });

    return critters[random(sizeof(critters))];
}


int wild(string str)
{
    if(going_wild)
    {
        tell_room(TO,"The world is already going wild.");
        return 1;
    }

    world_gone_wild_tm("");
    kill_stuff();
    return 1;
}




int world_gone_wild_tm(string str)
{
    int i;
    object *rooms,room,play;


    if(!objectp(TO)) { return 1; }



    going_wild = 1;
    rooms = objects();
    rooms = filter_array(rooms,"is_correct_room",TO);

    for(i=0;i<sizeof(rooms);i++)
    {
        if(!objectp(room = rooms[i])) { continue; }
        if((int)room->query_property("wild_timer") > time()) { continue; }

        if(random(10)) { continue; }
        go_wild(room);
    }


    call_out("world_gone_wild_tm",30);

    if(objectp(play=find_player("ares")))
    {
        if(play->query_property("debug_me"))
        {
            tell_object(play,"The world is going wild. Number of monsters: "+sizeof(wild_monsters)+"");
        }
    }
        
    return 1;
}



int go_wild(object room)
{
    object critter,play,*players=({});
    string mon;
    int i,rand,j,highest,num=0;

    if(!objectp(room)) { return 0; }

    wild_monsters -= ({ 0 });
    if(sizeof(wild_monsters) > 800) { return 0; }

    if(present("wild_world_monster",room)) { return 0; }

    room->set_property("wild_timer",time() + random(300));

    if(objectp(play=find_player("ares")))
    {
        if(play->query_property("debug_me"))
        {
            tell_object(play,"room: "+identify(room)+"");
        }
    }

    rand = roll_dice(1,3);

    players = all_living(room);
    players = filter_array(players,"is_non_immortal_player",FILTERS_D);

    if(sizeof(players))
    {
        for(i=0;i<sizeof(players);i++)
        {
            if(!objectp(players[i])) { continue; }
            highest = (int)players[i]->query_adjusted_character_level();
            if(highest > num) { highest = num; }
            rand += highest;
        }
    }

    if(!highest) { highest = 10; }

    if(rand > 10) { rand = 10; }

    for(i=0;i<rand;i++)
    {
        mon = get_critter();
        critter = new(mon);
        critter->move(room);
        critter->add_id("wild_world_monster");
        critter->set("aggressive",25);
        critter->set_speed(10);
        critter->set_max_hp(highest*3);
        critter->set_hp(highest*3);
        critter->set_attack_bonus(highest);
        critter->set_damage_bonus(highest/3);
        wild_monsters += ({ critter });
        critter->set_property("now_alive",30);
        j++;
    }

    wild_monsters -= ({ 0 });

    if(!j) { return 1; }

    if(j == 1)
    {
        tell_room(room,"%^GREEN%^A creature rushes madly in out of nowhere and attacks with abandon!");
        return 1;
    }

    tell_room(room,"%^GREEN%^Some creatures rush madly in from nowhere and attack with abandon!");
    return 1;
}


int target_filter(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj->id("wild_world_monster")) { return 0; }
    return 1;
}


void kill_stuff()
{
    object etp,tp,targ,*targets=({}),*attackers=({});
    int i,j,player;
    if(!objectp(TO)) { return; }

    wild_monsters -= ({ 0 });

    for(i=0;i<sizeof(wild_monsters);i++)
    {
        if(!objectp(tp = wild_monsters[i])) { continue; }
        if(!objectp(etp = environment(tp))) { continue; }

        targets = all_living(etp);
        targets = filter_array(targets,"is_non_immortal",FILTERS_D);
        targets = filter_array(targets,"target_filter",TO);

        player = 0;

        attackers = (object*)tp->query_attackers();

        if(!sizeof(targets)) { continue; }

        for(j=0;j<sizeof(targets);j++)
        {
            if(!objectp(targ = targets[j])) { continue; }
            if(member_array(targ,attackers) != -1) { continue; }

            tell_room(etp,"%^RED%^"+tp->QCN+" fearlessly attacks "+targ->QCN+"!");
            if(targ->is_player()) { player++; }
            tp->kill_ob(targ,0);
        }

        if(!player) { tp->set_property("now_alive",-1); }
        if((int)tp->query_property("no_alive") < 1)
        {
            tp->move("/d/shadowgate/void");
            tp->remove();
        }
    }
    call_out("kill_stuff",5);
}





int clean_up()
{
    return 1;
}