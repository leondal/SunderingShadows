//Grants access to elven refuge -- Yves 2/15/2018
//updated to make use of racial prejudice - Yves 2/28/2018
#include <std.h>
#include "../argabbr.h"
inherit INH+"argpath";

int climbed,echoes;
string step;

void create(){
    ::create();
    add_item(
        "trees",
            "You cannot identify what kind of trees they are, but one "
            "of them appears to have naturally occuring footholds of "
            "sorts that would aid climbing.");
    set_exits( (["west":PATH+"argpath10"]) );
    if(mobs) { make_creatures(); }
}

void init(){
    ::init();
    add_action("climb","climb");
    add_action("say_stuff","say");
}

int climb(string str){
    if(climbed){
        tell_object(TP,"%^GREEN%^Somebody is already trying that!%^RESET%^");
        return 1;
    }
    tell_room(ETP,
        "%^GREEN%^You see "+TPQCN+" start to %^RED%^climb%^GREEN%^ the large "
        "%^ORANGE%^tree%^GREEN%^.%^RESET%^",TP
    );
    tell_object(TP,"%^GREEN%^You start to %^RED%^climb%^GREEN%^ the large %^ORANGE%^tree%^GREEN%^.%^RESET%^");
    call_out("start_elf",1,TP);
    climbed = 1;
    return 1;
}


void start_elf(object person) {
    object prej;
    if(!present(person->query_name(),TO)) {
        tell_room(TO,
            "%^GREEN%^An %^MAGENTA%^elf%^GREEN%^ pokes its head over the side of its "
            "shelter.%^RESET%^"
        );
        tell_room(TO,"%^MAGENTA%^The elf says%^RESET%^: Hmm.");
        tell_room(TO,
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ shrugs and withdraws back into its "
            "shelter.%^RESET%^"
        );
        climbed = 0;
        return;
    }

    else {
        tell_room(environment(person),
            "%^GREEN%^An %^MAGENTA%^elf%^GREEN%^ pokes its head over the side of its "
            "shelter and carefully looks "+TPQCN+" over.%^RESET%^",person
        );
        tell_object(person,
            "%^GREEN%^An %^MAGENTA%^elf%^GREEN%^ pokes its head over the side of its "
            "shelter and carefully looks you over.%^RESET%^"
        );
        prej = new(OBJ+"prejudice_d");
        if(prej->query_elf_prejudice(person)) {
          tell_room(environment(person),
              "%^MAGENTA%^The elf says%^RESET%^: Begone foul beast! We want no help from your kind!"
          );
          tell_room(environment(person),
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ withdraws back into its shelter.%^RESET%^"
          );
          climbed = 0;
          return;
        }
        else call_out("start_exam",5,person);
   }
}

void start_exam(object person) {
    if(!present(person->query_name(),TO)) {
        tell_room(TO,"%^MAGENTA%^The elf says%^RESET%^: Gone then?");
        tell_room(TO,
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ shrugs and withdraws back into its "
            "shelter.%^RESET%^"
        );
        climbed = 0;
        return;
   }

    else {
        tell_room(TO,
            "%^MAGENTA%^The elf says%^RESET%^: What business do you have "
            "here, "+person->query_race()+"? Do you wish to aid us in "
            "the war against the %^BOLD%^%^RED%^Fey'ri%^RESET%^?"
        );
        person->set_property("asked",1);
        step = person->query_name();
        call_out("end_exam",20);
   }
}

void end_exam(string str) {
    tell_room(TO,
        "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ tires of waiting and withdraws back into "
        "its shelter.%^RESET%^"
    );
    find_player(step)->remove_property("asked");
    climbed = 0;
    return;
}

int say_stuff(string str) {
    if(!TP->query_property("asked")){
        return 0;
    }

    if((strsrch(str,"yes") != -1 || strsrch(str,"Yes") != -1)) {
        tell_room(ETP,
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ drops a rope %^RED%^ladder%^GREEN%^ to the %^CYAN%^ground%^GREEN%^ and "
            "allows "+TPQCN+" to climb up into the %^ORANGE%^tree%^GREEN%^.%^RESET%^",TP
        );
        tell_object(TP,
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ drops a rope %^RED%^ladder%^GREEN%^ to the %^CYAN%^ground%^GREEN%^ and "
            "allows you to %^RED%^climb%^GREEN%^ up.%^RESET%^"
        );
        TP->move_player(PATH+"platform01");
        tell_room(ETP,
            "%^ORANGE%^One of the %^MAGENTA%^elves%^ORANGE%^ drops a rope %^RED%^ladder%^ORANGE%^ to the "
            "%^CYAN%^ground%^ORANGE%^ and "+TPQCN+" comes climbing up.%^RESET%^",TP
        );
        tell_room(TO,"%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ then withdraws back into its shelter.%^RESET%^");
        remove_call_out("end_exam");
        find_player(step)->remove_property("asked");
        climbed = 0;
        return 1;
    }

    if((strsrch(str,"no") != -1 || strsrch(str,"No") != -1)) {
        tell_room(TO,"%^MAGENTA%^The elf says%^RESET%^: Then begone and leave us in peace!");
        tell_room(TO,"%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ withdraws back into its shelter.%^RESET%^");
        remove_call_out("end_exam");
        find_player(step)->remove_property("asked");
        climbed = 0;
        return 1;
    }

    else {
        tell_room(TO,
            "%^MAGENTA%^The elf says%^RESET%^: Either answer yes or no, I will give "
            "you time to think about your answer."
        );
        tell_room(TO,
            "%^GREEN%^The %^MAGENTA%^elf%^GREEN%^ shrugs and withdraws back into its "
            "shelter.%^RESET%^"
        );
        remove_call_out("end_exam");
        find_player(step)->remove_property("asked");
        climbed = 0;
    return 1;
    }
}

void start_echoes() {
    echoes = 1;
    switch(random(3)){
        case 0:
            tell_room(TO,
                "%^CYAN%^Faint whispers can be heard coming from somewhere up in "
                "the trees.%^RESET%^");
            call_out("start_echoes",(random(11)+30));
        break;
        case 1:
            tell_room(TO,
                "%^ORANGE%^You think you see a %^RED%^flash%^ORANGE%^ of movement come from high up "
                "in the trees.%^RESET%^");
            call_out("start_echoes",(random(11)+30));
        break;
        case 2:
            tell_room(TO,
                "%^GREEN%^Huge leaves drift and fall to the %^ORANGE%^ground%^GREEN%^ from the "
                "treetops high above.%^RESET%^");
            call_out("start_echoes",(random(11)+30));
        break;
        default:
            tell_room(TO,
                "Something is broken, please bug what you were doing.");
        break;
    }
    return;
}

void reset(){
    if(mobs) { make_creatures(); }
    ::reset();
    if(!echoes){call_out("start_echoes",(random(11)+10));}
}

