#include <std.h>
#include <objects.h>



inherit ROOM;

void create() 
{
  object ob;

  room::create();
  set_property("light",2);
  set_property("indoors",0);
  set_property("no_clean",1);
  set_short("mine entrance");
  set_long("%^BOLD%^RED%^ "
      "You are in the entrance of the deadly mine.  This mine was "
           "closed a long time ago because of how many people were killed in "
           "it.  The enterance here often is blocked by rock slides.  You get "
           "the feeling that you will most likely come out with less that you "
	   "have now.  The rock below your feet moves some, and you know a "
	   "rock slide is about to accure!");
  set_listen("default","The mountain rumbles with great power.");
  set_smell("default","You smell fresh dust in the air.");
  set_exits(([
         "mine" : "/d/mine2/rooms/mine2",
        "east" : "/d/shadow/room/grassland/grass21",
	   ] ));
  set_items(([
	      "cave" : "It is very old and dangerous and a sign reads-\n "
	               "%^RED%^STAY OUT!",
	      "mine" : "It is very dark and often blocked by a rock slide.",
	      "sign" : "%^BOLD%^WHITE%^If the cave happens to be blocked, "
                       "report the slide and the workers will clear it.\n"+
	               "They know what to do, but it may take a while for "
	               "them to come.",
	      "dust" : "The dust covers the air in a thick "
	               "brown color."
	   ] ));
   new("/d/mine2/obj/slide.c")->move(this_object());
}

void cleanit() 
{
  if(!present("slide"))
    {
      say("A landslide covers the mine enterance!");
      write("A landslide covers the mine enterance!");
      new("/d/mine2/obj/slide.c")->move(this_object());
      return 1;
    }
  if(present("workers"))
    {
      destruct(present("slide"));
      destruct(present("workers"));
      destruct(present("workercaller"));
      write("The workers have finished clearing the slide!");
      say("The workers have finished clearing the slide!");
      call_out("cleanit",15);
      return 1;
    }
  if(present("workercaller")) 
    {
      write("The workers come and start to clear the slide!");
      say("The workers come and start to clear the slide!");
      new("/d/mine2/obj/workers.c")->move(this_object());
        call_out("cleanit",20);
      return 1;
    }
}


init()
{
  ::init();
  add_action("report","report");
  add_action("leave","east");
}

int report(string str) 
{
  object ob;

  if(str == "slide")
    ob = present("slide");
  if(!ob) 
    {
      notify_fail("There is no reason to report the slide!\n");
      return 0;
    }
  ob = present("workercaller");
  if(!ob) 
    {
      write("You report the slide so that the workers will come and clear the "
	    "entrance to the cave.\n");
   say(this_player()->query_cap_name()+" reports the slide so that the workers will come and clear it"
                                  " so you can get into the mine.");
    new("/d/mine2/obj/workercaller.c")->move(this_object());
 call_out("cleanit",20);
      return 1;
}
    }
int leave(string str)
{
destruct(present("workercaller"));
return 1;
}







