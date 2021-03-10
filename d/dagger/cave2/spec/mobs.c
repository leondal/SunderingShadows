//added id of "cavemon" to mobs and check for present("cavemon") before letting
//reset add more to control excess pop. over several resets 
//also added check for userp on init so wandering mobs won't trigger reset
// *Styx* 5/4/02
//Updated to use CROOM to control the mobs over longer reboots.  I'm guessing this
//is going to result in more mobs on the first trip though, but less of the 
//overrun that we saw before.  I've preserved the numbers and proportions of mobs
//to be just about exactly like they were before.  -Ares 1/8/06

#include "/d/dagger/cave2/short.h"
#define BASE "/d/dagger/cave2/"

inherit CROOM;

int floor;
int flag;
int trapped;  // added to track if a trap is set *Styx* 1/21/06

int mobs; // global added for CROOM stuff - Ares

void set_floor(int x);
int query_floor();
string *get_rooms();
void do_ogres();
void do_demons(string file,int num,int chance);

void make_critters(); // more stuff for CROOM - Ares

void create() {
//    mobs = random(8); // will have to watch this and tweak accordingly -Ares
// to be consistent with the original & try to keep numbers in check *Styx* 1/21/06
    if(!random(2))   mobs = 1;
    if(mobs) { make_critters(); }
   set_repop(60);  // added a repop rate so it won't refill as fast *Styx* 1/21/06, made repop rate higher as was too easy and empty before *tsera* 9/30/06

    ::create();
    set_terrain(NAT_TUNNEL);
    set_travel(FOOT_PATH);
    if (random(30)) set_property("no teleport", 1);
    remove_property("light");
    set_property("light", random(2)+1);
    set_property("used sticks", 1);

    set_property("indoors", 1);
    set_short("Ogre caverns");
    set_long(
            "You are in a dark damp cavern system descending deep under the mountain.  All around you you see signs of ogre habitation, from fistmarks in the walls to the unmistakable odor.  As you peer into the dark abyss before you you see many glowing eyes peering back at you."
    );
    set_listen("default", "You hear the thunder of hundreds of huge footfalls as they race towards you through the dark.");
    set_smell("default", "You're not sure you want to know what that is.");

    set_items( ([
       "fistmarks" : "   There are several marks gouged into the walls that were most likely made by some very angry ogres.",
       "eyes" : "   The glowing red eyes peer deep into you, deep into your soul, tormenting you with their deep hatred, instilling a great fear in your gut.",
       "walls" : "   These walls are pockmarked and have been brutally abused.",
    ]) );
}

void init() {
    if(flag && userp(TP) && !TP->query_true_invis()){
        flag = 0;
    }
    ::init();
}

void reset() {

    string *exits, dir;
    if(!objectp(TO)) { return; }
// added check for cavemon, don't load more if some have wandered in *Styx*
    if(mobs && !present("cavemon")) { 
	make_critters(); 
    }

    ::reset();
    if(!trapped) {  // added check to only remove when not trapped *Styx* 1/21/06
	    remove_item("tripwire");
	    remove_item("ground");
    }
    if(!pointerp(TO->query_exits()) || !sizeof(TO->query_exits()) ){
      flag = 1;
      return;
    }
// over longer reboots, this could eventually put traps in all rooms and on all exits and even multiples on the same exit, so... don't add a trap if is there is one
// was just...  (if(!random(40)) {
    if(!random(40) && !trapped){
      exits = (string *)TO->query_exits();
      dir = exits[random(sizeof(exits))];
      set_trap_functions( ({dir}), ({"cavein"}), ({dir}) );
      add_item("tripwire", "This tripwire is rigged to cause a cavein!");
      add_item("ground", "There is a tripwire rigged across the ground to the "+dir);
      trapped = 1;
    }
}

void set_floor(int x) {
    floor = x;
}

int query_floor() {
    return floor;
}

// BEGIN MONSTER CREATION CODE
void make_critters() // added for CROOM stuff -Ares
{
    if(has_mobs()) { return; }
    if(mons) { mons = ([]); }

    switch(query_floor())
    {
    case 1:

        if(random(5)) 
        {
            if(!random(4)) 
            {
                set_monsters(({MPATH"ogre2",MPATH"ogre1"}),({roll_dice(1,2),roll_dice(1,3)}));
                return;
            }
            set_monsters( ({MPATH"ogre1"}),({roll_dice(1,3)}));
            return;
        }
        if(!random(10))
        {
      if(!random(8))
            {
                set_monsters(({MPATH"demon"}),({ 2 }));
                return;
            }
            set_monsters(({MPATH"demon",MPATH"demon2b"}),({ 1,1 }));
            return;
        }
        set_monsters(({MPATH"demon"}),({ 1 }));
        return;

    case 2:

        if(random(3)) { do_ogres(); return; }

        switch (random(9)) 
        {
        case 0:
         do_demons("G_demon",1,18); return;
        case 1:
         do_demons("summoner2",1,8); return;
        case 2:
         do_demons("berserker2",1,13); return;
        case 3:
        case 4:
        case 5:
            do_demons("demon",2,10); return;
        case 6:
        case 7:
        case 8:
            do_demons("demon2b",2,10); return;
        default:
            do_demons("demon",1,0); return;
        }
        return;

    case 3:

        if(random(2)) { do_ogres(); return; }

        switch(random(11)) 
        {
        case 0:
         do_demons("crone",1,15); return;
        case 1:
        case 2:
            do_demons("summoner",1,10); return;
        case 3:
        case 4:
            do_demons("berserker",2,10); return;
      case 5:
         do_demons("demon",2,10); return;
       case 6:
         do_demons("summoner2",1,10); return;
            do_demons("G_demon",2,10); return;
        case 7:
      case 8:
         do_demons("summoner2",1,10); return;
      case 9:
         do_demons("berserker2",1,15); return;
        case 10:
            do_demons("G_demon",4,15); return;
        default:
            do_demons("demon",1,0);
            return;
        }
        return;

        default:
            return;
    }
    return;
}

// changed to work with CROOM -Ares
void do_demons(string file,int num,int chance) 
{  
    if(!random(chance)) { set_monsters(({ MPATH file }),({ roll_dice(1,num) }) ); return; }

    switch(random(10)) 
    {
    case 9:
    case 8:
        set_monsters(({MPATH file,MPATH"G_demon"}),({ num,1 })); return;
    case 7..4:
        set_monsters(({MPATH file,MPATH"demon"}),({ num,roll_dice(1,2) })); return;
    case 3..0:
        set_monsters(({MPATH file,MPATH"demob2b"}),({ num,roll_dice(1,2) })); return;
    default:
    }
}

// more CROOM changes -Ares
void do_ogres() //Moves a random 'troop' of ogres into the room.
{
    if(!random(3)) 
    {
        if (!random(4)) 
        {
            if (!random(6)) 
            {
                if (!random(8)) 
                {
                    if (!random(10))
                    {
                        set_monsters(({MPATH"ogre6",MPATH"ogre5",MPATH"ogre4",MPATH"ogre3",MPATH"ogre2",MPATH"ogre1"}),
                            ({ 1, roll_dice(1,3),roll_dice(1,4),roll_dice(1,6),roll_dice(1,7),roll_dice(1,8) }));
                        monster_party(60);
                        return;
                    }
                    set_monsters(({MPATH"ogre5",MPATH"ogre4",MPATH"ogre3",MPATH"ogre2",MPATH"ogre1"}),
                        ({ roll_dice(1,3),roll_dice(1,4),roll_dice(1,6),roll_dice(1,7),roll_dice(1,8) }));
                    monster_party(60);
                    return;                    
                }
                set_monsters(({MPATH"ogre4",MPATH"ogre3",MPATH"ogre2",MPATH"ogre1"}),
                    ({ roll_dice(1,4),roll_dice(1,6),roll_dice(1,7),roll_dice(1,8) }));
                monster_party(60);
                return;                  
            }
            set_monsters(({MPATH"ogre3",MPATH"ogre2",MPATH"ogre1"}),
                ({ roll_dice(1,6),roll_dice(1,7),roll_dice(1,8) }));
            monster_party(60);
            return;
        }
        set_monsters(({MPATH"ogre2",MPATH"ogre1"}),
            ({ roll_dice(1,7),roll_dice(1,8) }));
        monster_party(60);
        return;
    }
    set_monsters(({MPATH"ogre1"}),({ roll_dice(1,8) }));
    monster_party(60);
    return;
}
// END MONSTER CREATION CODE


//BEGIN MISC CODE
string *get_rooms() {
    string *rooms, *rooms2;
    int i;

    rooms = get_dir(BASE);
    rooms2 = ({});

    for (i=0;i<sizeof(rooms);i++) {
        rooms2 += ({BASE + rooms[i]});
    }
    rooms2 -= NOTROOMS;

    return rooms2;
}

int crack_fcn(string str){
    string place;
    string *rooms;
    int j;

    if(str != "crack"){
        return notify_fail("Enter what?\n");
    }

    tell_object(TP, "%^BOLD%^%^BLUE%^You walk slowly into the glowing crack.\n");
    tell_object(TP, "%^BOLD%^%^BLUE%^As you walk deeper into the crack you can feel the light bathing you in its glow as it gets brighter and brighter.\n");
    tell_object(TP, "%^BOLD%^%^BLUE%^You are unable to stop, you keep moving forward as the intensity of the light grows.  You are soon blind but you continue moving on.\n\n");
    tell_object(TP, "%^BOLD%^%^BLUE%^Suddenly there is a great flash and the light disapears, leaving you in a different place.\n");
    tell_room(environment(TP), "%^BOLD%^%^BLUE%^"+TP->query_cap_name()+" walks into the strange crack, the blue light bathing "+TP->query_objective()+" in its strange light.");

    if(random(3)){    
        rooms = get_rooms();
        place = rooms[random(sizeof(rooms))];
      TP->move_player(place);
    } else {
        TP->move_player("/d/dagger/cave2/cave2.c");
    }
    return 1;
}

//END MISC CODE

//BEGIN TRAP CODE
int cavein(){
    string verb, exit;
    object *followers;
    int i;

    if(!interactive(TP)) return 1;
    verb = query_verb();
    followers = TP->query_followers();
    if(!followers) followers = ({});
    
    tell_object(TP, "As you move "+verb+" your foot catches on a wire and you trip forward as the room starts to collapse down around you!");
    TP->do_damage("torso", roll_dice(5,10));
    if(followers != ({})){
        tell_object(TP, "Some of your companions try to dive through after you!");
    }
    for(i = 0;i<sizeof(followers);i++){
     if(!objectp(followers[i])) continue;
        if(followers[i]->query_stats("dexterity") > random(30)) continue;
        followers -= ({followers[i]});
    }
    
    exit = query_exit(verb);

    for(i = 0;i<sizeof(followers);i++){
      if(!objectp(followers[i])) continue;
        tell_object(followers[i], "As "+TPQCN+" moves "+verb+", you quickly dive after "+TP->query_objective()+", the ceiling collapsing down on top of you!");
        followers[i]->do_damage("torso", roll_dice(5,10));
        followers[i]->move_player(exit);
    }
    TP->move_player(exit);
    tell_room(TO, "You cover your eyes as the ceiling comes crashing down around you!", ({TP})+followers);
    
    collapse_exit(verb, 400);

    return 1;
}

//END TRAP CODE
