#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",-7);
    set_property("indoors",1);
    set_short("A REALLY BAD place to be.");
    set_long("
    YOU REALLY DON'T WANT TO KNOW!
");

     set_listen("default","%^BOLD%^%^RED%^YOU WERE WARNED!");
     set_smell("default","It is very musty down here, and smells strongly of decay.");
 
    set_exits(([

      "north" : "/d/attaya/tower/doom3",

    ] ));
}

void reset(){
       int num, i;
      ::reset();
       if(!present("tyrant")){
                num = random(6)+1;
                for(i=0;i<num;i++)
                       new("/d/attaya/mon/tyrant2")->move(TO);
       }
}
