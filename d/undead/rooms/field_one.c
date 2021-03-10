#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();
    set_repop(25);

    ::create();

    set_name("A battlefield");
    set_terrain(BARREN);
    set_travel(RUTTED_TRACK);
    set_climate("temperate");
    set_property("light", 2);

    set_short("%^BOLD%^%^RED%^You are in the middle of a Battle Field%^RESET%^");
    
    set_long("%^BOLD%^%^RED%^You are in the middle of a Battle Field.%^RESET%^\n"
        "%^RED%^All around you bodies lay strewen as if they were dolls, "  
        "tossed aside by an angry god. Pieces of flesh litter the landscape "
        "for as far as you can see. Faces of noble warriors fallen in battle "
        "stare at you with bloodshot eyes and terrifying expressions. This "
        "sight probably brings Kartakass great pleasure, but it just makes "
        "you sick to your stomach.");

    set_exits(([
        "path"      :BO+"path39",
        "south"     :BF+"room2"
             ]));

    set_smell("default","You are made sick by the stench of death.");
    set_listen("default","You hear the sounds of war being waged.");
}

void make_creatures()
{
    int i,monsters;
    object *mobs;
    monsters = has_mobs();
    if(!monsters) 
    {
        if(mons) { mons = ([]); }
        
        switch(random(100))
        {
        case 0..40:
            set_monsters(({MON"skeleton.c"}),({roll_dice(1,3)}));
            break;
        case 41..60:
            if(base_name(TO) == BF"room34") { make_creatures(); return; }
            set_monsters(({MON"guardian_maker.c"}),({roll_dice(1,2)}));
            break;
        case 61..80:
            set_monsters(({MON"skeleton_maker.c"}),({roll_dice(1,2)}));
            break;
        case 81..90:
            set_monsters(({MON"skeletal_knight.c"}),({ 1 }));
            break;
        case 91..95:
            set_monsters(({MON"skeletal_infantry.c"}),({ 1 }));
            break;
        case 96..99:
            set_monsters(({MON"undead_beast.c"}),({ 1 }));
            break;
        }
    }

   return;
}

int is_junk(object obj)
{
    if(obj->id("summoned monster")) return 0;
    if(obj->id("corpse")) return 0;
    if(!living(obj)) return 1;
    else return 0;
}

void reset()
{
    int i;
    object *junk;
    ::reset();
    if(!random(3)) // A necessary evil here to prevent accumulation of stuff over huge uptimes
    {
        if(junk=filter_array(all_inventory(TO),"is_junk",TO))
        {
            for(i=0;i<sizeof(junk);i++)
            {
                junk[i]->remove();
            }
        }
    }
    return;
}


//object *people;
//int i;

//set_heart_beat(1);
//set_property("continue heartbeat",1);

/*
void heart_beat(){
   ::heart_beat();
    people = all_living(TO);
    if(random(100) < 8){
	tell_room(TO,
        "%^BOLD%^%^RED%^A giant flaming boulder comes flying into "
        "the room striking the earth, and sending rock bits flying "
        "everywhere!"
        );
    for(i=0;i<sizeof(people);i++){
    if(!interactive(people[i])) continue;
    if(!SAVING_D->saving_throw(people[i],"paralyzation_poison_death")){
	tell_object(people[i],
        "%^GREEN%^You are hit by the boulder and struggle to get "
        "out from under it!"
      );
	tell_room(TO,people[i]->query_cap_name()+" gets flattened under the boulder!",people[i]
	);
	people[i]->do_damage(people[i]->return_target_limb(),roll_dice(4,6));
	people[i]->add_attacker(TO);
	people[i]->continue_attack();

	people[i]->set_paralyzed(random(10)+5,
        "You are trapped under the boulder and struggling to get free!"
      );
      } else {
	people[i]->do_damage(people[i]->return_target_limb(),roll_dice(2,6));
	people[i]->add_attacker(TO);
	people[i]->continue_attack();
	tell_object(people[i],
	"Shards of the boulder stab into you!"
	);
      }
  }
      return 1;
    }
}*/
