#include "../undead.h"
#include "../desert.h"

inherit CROOM;

void setup_room(string str);
void make_creatures();

object setter;

void create() 
{
    make_creatures();
    set_repop(10);

    ::create();

    set_name("The vast Sangri Desert");
    set_terrain(DESERT);
    set_travel(DIRT_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_climate("desert");
    set_property("peer limit", roll_dice(1,4)+3);

    set_long("You are in a vast desert.  To the north you see a path leading up into "
        "the mountains.  A mighty mountain range runs as far as you can see to the "
        "east and to the west.  Everywhere else all you can see is desert.  ");

    setup_room(base_name(TO));

    set_exits(([
        "east"      :DES+"desert_0,1",
        "south"     :DES+"desert_1,0",
             ]));
    setter = find_object_or_load(SETTER); // Places random exit in the desert -Ares
}

void setup_room(string str)
{
    string room_name,desc,short_desc,smell,sound;

    if(!objectp(TO))            { return; }

    room_name = replace_string(str,DES"desert_","");

    if(member_array(room_name,NORTH) != -1)             { desc = N_DESC;   short_desc = S_N;   smell = SM_N;   sound = SO_N;   } 
    else if(member_array(room_name,EAST) != -1)         { desc = E_DESC;   short_desc = S_E;   smell = SM_E;   sound = SO_E;   } 
    else if(member_array(room_name,SOUTH) != -1)        { desc = S_DESC;   short_desc = S_S;   smell = SM_S;   sound = SO_S;   } 
    else if(member_array(room_name,WEST) != -1)         { desc = W_DESC;   short_desc = S_W;   smell = SM_W;   sound = SO_W;   } 
    else if(member_array(room_name,NORTHEAST) != -1)    { desc = NE_DESC;  short_desc = S_NE;  smell = SM_NE;  sound = SO_NE;  } 
    else if(member_array(room_name,SOUTHEAST) != -1)    { desc = SE_DESC;  short_desc = S_SE;  smell = SM_SE;  sound = SO_SE;  } 
    else if(member_array(room_name,SOUTHWEST) != -1)    { desc = SW_DESC;  short_desc = S_SW;  smell = SM_SW;  sound = SO_SW;  } 
    else if(member_array(room_name,NORTHWEST) != -1)    { desc = NW_DESC;  short_desc = S_NW;  smell = SM_NW;  sound = SO_NW;  }
    else if(member_array(room_name,MIDDLE) == -1)       { desc = MID_DESC; short_desc = S_MID; smell = SM_MID; sound = SO_MID; }

    set_short(short_desc);
    set_long( short_desc +"\n"+ ::query_long() + desc +"\n");
    set_smell("default",smell);
    set_listen("default",sound);

    return;
}

void make_creatures()
{
   int monsters;
   monsters = has_mobs();
   if(!monsters) 
   {
        if(mons) { mons = ([]); }
        
        switch(random(100))
        {
        case 0..20:
            break;
        case 21..50:
            set_monsters(({MON"zombie.c"}),({roll_dice(1,2)}));
            break;
        case 51..80:
            set_monsters(({MON"skeleton.c"}),({roll_dice(1,2)}));
            break;
        case 81..90:
            set_monsters(({MON"skeletal_infantry.c"}),({ 1 }));
            break;
        case 91..95:
            set_monsters(({MON"skeletal_knight.c"}),({ 1 }));
            break;
        case 96..99:
            set_monsters(({MON"undead_beast.c"}),({ 1 }));
            break;
        }
   }
   return;
}
