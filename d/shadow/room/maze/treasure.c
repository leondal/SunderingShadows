inherit "/std/room";
object ob;
create() {
::create();
set_light(2);
set_indoors(1);
set_short("treasure room");
set_long("You are in a area where there is treasure all around!");
set_exits( ([ "out" : "/d/shadow/room/maze/enterance.c",
]) );
new("/d/shadow/room/maze/mon/dog.c")->move(this_object());
}

init()
{
  ::init();
  if(!ob || member_array(ob, all_inventory(this_object())) == -1)
    if(random(5) == 1)
     {
       switch(random(5))
        {
          case 0: ob  = new("/d/shadow/room/maze/mon/seth.c");
                  break;
          case 1: ob  = new("/d/shadow/room/grassland/mon/haw.c");
                  break;
          case 2: ob  = new("/d/shadow/room/maze/mon/messenger.c");
                  break;
          case 3: ob  = new("/d/shadow/room/maze/mon/sally.c");
                  break;
          case 4: ob  = new("/d/shadow/room/grassland/mon/sharf.c");
                  break;
        }
       ob -> move(this_object());
     }
}
