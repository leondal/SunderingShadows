#include "../undead.h"

inherit CROOM;

void make_creatures();

void create() 
{
    make_creatures();
    set_repop(25);

    ::create();

    set_name("The Bog of Despair");
    set_terrain(SWAMP);
    set_travel(FRESH_BLAZE);
    set_climate("tropical");
    set_property("light", 1);
    set_property("no teleport",1);
   
    set_short("%^BLUE%^You are in the Bog of Despair%^RESET%^");
   
    set_long("%^BLUE%^You are in the Bog of Despair%^RESET%^%^GREEN%^\n"
        "The ground here is covered with %^YELLOW%^decaying plant matter"
        "%^RESET%^%^GREEN%^ which barely seems to be able to hold your weight.  "
        "The trees here are hollow and long since dead, only their rotting "
        "trunks remain now.  In some places the ground looks very %^BOLD%^"
        "unstable%^RESET%^%^GREEN%^, and you dare not venture too far from "
        "those areas which appear to be safe.  You think it would be "
        "%^RESET%^%^BOLD%^impossible%^RESET%^%^GREEN%^ to return to the "
        "surface should you fall through the top layer of the bog.  The few "
        "things left alive here seem to struggle upward in the futile attempt "
        "to get some sunlight.  Looking up, you notice a sort of %^BLUE%^inky "
        "blackness%^RESET%^%^GREEN%^ that covers the sky and prevents most of "
        "the light from reaching the floor of the bog.");

    set_items(([
        "plants":"%^YELLOW%^%^BOLD%^The dead plants form a thick layer over the water beneath. They %^RESET%^%^BOLD%^should%^RESET%^%^YELLOW%^ hold your weight.%^RESET%^",
        "plant matter":"%^YELLOW%^%^BOLD%^The dead plants form a thick layer over the water beneath. They %^RESET%^%^BOLD%^should%^RESET%^%^YELLOW%^ hold your weight.%^RESET%^",
        "trees":"%^YELLOW%^The trees here have been dead for a long time. They are saturated with water and look like they would fall apart at the slightest touch.%^RESET%^",
        "trunks":"%^YELLOW%^The trees here have been dead for a long time. They are saturated with water and look like they would fall apart at the slightest touch.%^RESET%^",
        "ink":"%^BLUE%^This layer of blackness appears to be %^MAGENTA%^magical%^RESET%^%^BLUE%^ in nature and prevents the growth of almost every plant in this area, it also seems to make the air especially humid here.%^RESET%^",
        "blackness":"%^BLUE%^This layer of blackness appears to be %^MAGENTA%^magical%^RESET%^%^BLUE%^ in nature and prevents the growth of almost every plant in this area, it also seems to make the air especially humid here.%^RESET%^",
             ]));

    set_exits(([
        "northeast" :SWMP+"swamp2",
        "northwest" :SWMP+"swamp21",
        "south"     :SWMP+"out",
             ]));

    set_smell("default","The air is thick with the smell of stagnant water.");
    set_listen("default","%^GREEN%^%^BOLD%^You hear the sound of your feet on the surface of the bog.");

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
        case 0..50:
            set_monsters(({MON"zombic_hands.c"}),({roll_dice(1,2)}));
            break;
        case 51..80:
            set_monsters(({MON"wererat.c"}),({roll_dice(1,2)}));
            break;
        case 81..90:
            set_monsters(({MON"wyvern.c"}),({ 1 }));
            break;
        case 91..99:
            set_monsters(({MON"undead_beast.c"}),({ 1 }));
            break;
        }
   }
   return;
}



/*
object *people;
int i;


void heart_beat() {
   ::heart_beat();
   people = all_living(TO);
   if(random(100) < 1) {
      tell_room(TO,
         "%^BOLD%^Suddenly, hands shoot up from the floor of the bog, grabbing at your feet!"
      );
   for(i=0;i<sizeof(people);i++){
      if(!SAVING_D->saving_throw(people[i],"spells")){
         tell_object(people[i],
         "%^RED%^%^BOLD%^You feel two of the hands grasp your legs and begin to pull you through the surface of the Bog!"
         );
      tell_room(TO,people[i]->query_cap_name()+" is grasped at by two of the hands and begins to be pulled under!",people[i]);
      this_object()->new(SWMON+"hands");
   } else {
      tell_object(people[i],"%^BLUE%^%^BOLD%^You manage to avoid the grasp of the hands!");
   }
   }
   return 1;
   }
}
void heart_beat() {
   ::heart_beat();
   people = all_living(TO);
   if(random(200) < 1) {
      new(SWMON+"hands")->move(this_object());
   }
}*/
