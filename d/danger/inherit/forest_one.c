#include "forest.h"
#include "../danger.h"

inherit MINHERIT;

void setup_room(string str);
void make_creatures();


void create() {
   //make_creatures();
   //set_repop(10);
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set_terrain(HEAVY_FOREST);
   set_travel(FRESH_BLAZE);
   set_name("%^RESET%^%^GREEN%^In the Great Forest");
   set_property("peer limit", roll_dice(1,4)+3);
   setup_room(base_name(TO));
}


void setup_room(string str){
   string room_name,desc,smell,sound,n_desc;
   if(!objectp(TO))            { return; }
   room_name = replace_string(str,FOREST"forest_","");

    if(member_array(room_name,NORTH) != -1)             { desc = N_DESC;   n_desc = N_N;   smell = SM_N;   sound = SO_N;   } 
    else if(member_array(room_name,EAST) != -1)         { desc = E_DESC;   n_desc = N_E;   smell = SM_E;   sound = SO_E;   } 
    else if(member_array(room_name,SOUTH) != -1)        { desc = S_DESC;   n_desc = N_S;   smell = SM_S;   sound = SO_S;   } 
    else if(member_array(room_name,WEST) != -1)         { desc = W_DESC;   n_desc = N_W;   smell = SM_W;   sound = SO_W;   } 
    else if(member_array(room_name,NORTHEAST) != -1)    { desc = NE_DESC;  n_desc = N_NE;  smell = SM_NE;  sound = SO_NE;  } 
    else if(member_array(room_name,SOUTHEAST) != -1)    { desc = SE_DESC;  n_desc = N_SE;  smell = SM_SE;  sound = SO_SE;  } 
    else if(member_array(room_name,SOUTHWEST) != -1)    { desc = SW_DESC;  n_desc = N_SW;  smell = SM_SW;  sound = SO_SW;  } 
    else if(member_array(room_name,NORTHWEST) != -1)    { desc = NW_DESC;  n_desc = N_NW;  smell = SM_NW;  sound = SO_NW;  }
    else if(member_array(room_name,MIDDLE) == -1)       { desc = MID_DESC; n_desc = N_MID; smell = SM_MID; sound = SO_MID; }

   set_short("%^RESET%^%^GREEN%^In The Great Forest");
   set_long( LONG + desc);
   set("night long", NLONG + n_desc);
   set_smell("default",smell);
   set_listen("default",sound);

    return;
}
/*
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
*/