inherit "/std/monster";
#include "std.h";

create(){
    ::create();
set_name("a bed");
set_id(({"a bed", "bed"}));
set_short("a bed in the shape of a dragon");
set_long("%^BOLD%^RED%^The bed is in the shape of a dragon, with wing half furled.  The head board contains the shoulders and head of the dragon and its eyes glare balefully at you by the light of the hanging globes");
set_gender("neuter");
set("race", "bed");
set_body_type("dragon");
   set_level(15);
   set_alignment(2);
   set("aggressive",1);
   set_size(3);
   set_stats("intelligence",16);
   set_stats("wisdom",17);
   set_stats("strength",18);
   set_stats("charisma",15);
   set_stats("dexterity",16);
   set_stats("constitution",18);
set_exp(5000);
   set_hd(15,3);
   set_sp(1700);
   set_max_sp(2000);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_max_mp(0);
   set_mp(query_max_mp());
	add_money("gold", random(5000));
}

init(){
    ::init();
add_action("order_drag","DRAGONS");
}

int order_drag(string str){
    string player=(this_player()->query_cap_name());
string first_word, rest_of_line;
    if(str == "DIE"){
        if(player!="Vashkar"){
            command("kill "+player);
            return 1;
        }
        add_hp(-10000);
    return 1;
    }
    if(str=="SHUT UP"){
        if(player!="Vashkar"){
            command("kill "+player);
            return 1;
        }

    return 1;
    }
    sscanf(str, "%s %s", first_word, rest_of_line);
    if(first_word == "KILL"){
        if(player!="Vashkar"){
            command("kill "+player);
            return 1;
        }
        if(!rest_of_line || !present(rest_of_line)){
            return 1;
        }
        command("kill "+rest_of_line);
        return 1;
    }
    return 0;
    }
