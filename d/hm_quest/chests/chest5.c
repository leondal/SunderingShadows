#include <std.h>
#include <ansi.h>

#define CLS ESC+"[H"+ESC+"[2J"

void write_wheel(int ansi);
void chest_solved();

inherit OBJECT;

int ansi, using;
string *wheel;

void create()
{
  ::create();
   set_name("rusted chest");
  set_id( ({ "strange chest", "rusted chest", "chest" }) );
  set_short("a strange rusted chest");
  set_long("At first glance, it would appear that it was a rusty chest, but "
       "at closer inspection the chest is made of rust colored wood. Its "
       "details just as sharp and clear as if it was new. There is no "
           "keyhole, but it seems locked. There is a strange metal plaque "
	   "with a riddle on the front of it.");
  set_weight(100000);
  using = 0;
  wheel = ({"C","R","A","J","S"});
}

void init()
{
  ::init();
  add_action("read","read");
  add_action("read","look");
}

int read(string str)
{
  string term;

  if( str != "plaque" )
    return 0;
  if(TP->query_lowest_level()<19){
  	write("You can make no sense of the writing on the plaque.");
  	tell_room(environment(TP),TP->query_cap_name()+" struggles to make sense of the writing.",TP);
  	return 1;
  }
  else{
  if( using )
    {
      write("Someone is already working on opening the chest.");
      return 1;
    }
  using = 1;
  if( (term = (string)TP->getenv("TERM")) == "ansi" || term == "xterm" || 
     term == "ansi-status")
    ansi = 1;
  else
    ansi = 0;
  write_wheel(ansi);
  message("prompt",">>> ",TP);
  input_to("turn_wheel");
  return 1;
  }
}

void turn_wheel(string str)
{
  switch(str)
    {
      case "1" :
	switch( wheel[0] )
	  {
       case "C":
          wheel[0] = "W";
	      break;
       case "W":
          wheel[0] = "T";
	      break;
       case "T":
          wheel[0] = "F";
	      break;
       case "F":
          wheel[0] = "C";
	      break;
	    }
	break;
      case "2" :
	switch( wheel[1] )
	  {
       case "R":
          wheel[1] = "H";
	      break;
       case "H":
          wheel[1] = "A";
	      break;
       case "A":
          wheel[1] = "L";
	      break;
       case "L":
          wheel[1] = "R";
	      break;
	    }
	break;
      case "3" :
	switch( wheel[2] )
	  {
       case "A":
          wheel[2] = "T";
	      break;
       case "T":
          wheel[2] = "E";
	      break;
	   case "E":
          wheel[2] = "D";
	      break;
       case "D":
          wheel[2] = "A";
	      break;
	    }
	break;
      case "4" :
	switch( wheel[3] )
	  {
	   case "J":
	      wheel[3] = "S";
	      break;
	   case "S":
	      wheel[3] = "O";
	      break;
	   case "O":
	      wheel[3] = "E";
	      break;
	   case "E":
	      wheel[3] = "J";
	      break;
	    }
	break;
      case "5" :
	switch( wheel[4] )
	  {
	   case "S":
	      wheel[4] = "T";
	      break;
	   case "T":
	      wheel[4] = "R";
	      break;
	   case "R":
	      wheel[4] = "M";
	      break;
	   case "M":
	      wheel[4] = "S";
	      break;
	   }
	break;
      default  :
	write("You give up on the puzzle, and go back to more important "
	      "things.");
	say( TP->query_cap_name() +" gives up on the riddle, and goes back to "
	    "important things.");
	using = 0;
	return;
	break;
    }
  if( wheel[0] == "W" && wheel[1] == "A" && 
      wheel[2] == "T" && wheel[3] == "E" &&
      wheel[4] == "R")
    {
      write_wheel(ansi);
      write("With a THUNK, the chest opens up.\n");
      say( TP->query_cap_name() +" solves the puzzle and the chest opens "
	  "with a THUNK!");
      chest_solved();
      return;
    }
  write_wheel(ansi);
  message("prompt",">>> ",TP);
  input_to("turn_wheel", ansi);
}

void chest_solved()
{
  write("The chest spits an object and piece of paper at you, and then crumbles to dust before "
	"your eyes.");
  new("/d/hm_quest/obj/pommel1.c")->move(environment(TO));
  new("/d/hm_quest/obj/note3a.c")->move(environment(TO));
  say("The chest spits something to "+ TP->query_cap_name() +" and then "
      "disintegrates before your eyes.");
  remove();
}

void write_wheel(int ansi)
{
  if(ansi)
    write(CLS);
  say( TP->query_cap_name() +" stares at the chest, and tries to solve it's "
      "riddle.");
  write("There is a little inscription on the plaque, and a set of rolling "
	"letters below. You figure that you turn the letters to form the "
	"answer to the riddle and it will open.\n\nType the number of the "
	"letter wheel to change, any other key, or just enter to give up.\n");
  write("%^BOLD%^What runs smoother than a rhyme,\n"
  		"Loves to fall, but cannot climb?\n"
  		);
  write("%^BOLD%^%^BLUE%^   1   2   3   4   5\n");
  write("%^BOLD%^%^GREEN%^   "+ wheel[0] +"   "+ wheel[1] +"   "+
	wheel[2] +"   "+ wheel[3] +"   "+ wheel[4] +"\n");
}



