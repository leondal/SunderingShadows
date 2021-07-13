// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"concourse";

void create(){
    ::create();
    set_long(::query_long()+"\n%^RESET%^");
    set_exits(([
        "southwest" : ROOMS"concourse2",
        "east" : ROOMS"concourse5",
        ]));
}

void reset(){
    ::reset();
    if(!present("gil")) new(MON "gil")->move(TO);
    if(!present("servingcart")) new(OBJ "concessions")->move(TO);
}

void init(){
    ::init();
    add_action("read_fun","read");
}

int read_fun(string str){
    object ob;
    
    if(str!="menu")
        return 0;
    if(!present("gil")){
        write("What's the point, there's no one here to take your order?");
        return 1;
    }
    
    ob=present("gil");
    
    write("\n");
    write("%^YELLOW%^---===| %^WHITE%^The Concourse Snack Bar %^ORANGE%^|===---%^RESET%^");
    write("\n");
    write("%^YELLOW%^   Popcorn              %^WHITE%^"+(int)ob->get_price("popcorn")+" silver%^RESET%^");
    write("%^RESET%^%^RED%^     Turkey Leg           %^BOLD%^%^WHITE%^"+(int)ob->get_price("turkey leg")+" silver%^RESET%^");
    write("%^RESET%^%^ORANGE%^       Beer                 %^BOLD%^%^WHITE%^"+(int)ob->get_price("beer")+" silver%^RESET%^");
    write("\n");
    write("%^YELLOW%^------======|+|+|+|+|+|+|+|======------%^RESET%^");
    write("\n");
    return 1;
}

