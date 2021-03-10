#include <std.h>
#include "../defs.h"
#include <daemons.h>
inherit ROOM;

int RED,WHITE,GREEN,BLUE,YELLOW,rin,yin,bin,gin,counter;
mapping color;
void doit(int x);
void checkit();
void checkdone();
string flipit(string str);
void number_check(int one,int two,int three,int four);

void create()
{
	
  ::create();
   set_terrain(BARREN);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no scry",1);
   set_short("%^BOLD%^The Pedestal Chamber%^RESET%^");
   set_long("%^BOLD%^You find yourself standing in what appears "+
   	"to be the middle of a hollowed out crystal.  The area "+
     	"is bathed in a %^MAGENTA%^rose%^WHITE%^ colored light,"+
	" that seems to shine "+
      "through the crystal above your head.  Through the "+
      "walls, you see chaotic images fluttering around you.  "+
      "Scenes of all types of activities flash by, from children "+
      "at play, to snow-capped mountains, to armies in battle.  "+
      "In the center of the chamber a large %^CYAN%^pedestal%^WHITE%^"+
	" reaches up "+
      "from the floor.  The entire chamber, pedestal and all, "+
      "appears as if it was crafted from one gigantic crystal.\n");       
  set_listen("default","%^BOLD%^%^CYAN%^A steady, soft hum from the pedestal "+
        "echoes in this small chamber.");
  set_items(
    ([
    "pedestal" : (: TO,"l_crys" :)
    ]) );
  set_exits(
    ([
    "green" : ROOMS+"forest1",
    "red" : ROOMS+"fire",
    "blue" : ROOMS+"good2",
    "yellow" : ROOMS+"good1"
    ]) );
}

void init()
{
  ::init();
  add_action("look pedestal","l_crys");
  add_action("press","press");
  add_action("insert","insert");
  add_action("restart","restart");
}

void insert(string str)
{
    object obj;
  number_check(rin,gin,bin,yin); 
  if((rin + gin + bin + yin) == 4)
  {
    tell_room(TP,"%^BOLD%^All of the crystals have been inserted!");
    return 1;
  }
  if(!str)
  {
      tell_room(TP,"You need to %^RED%^insert crystal%^RESET%^.");
    return 1;
  }
	if(str == "blue" || str == "blue crystal")
  {  
    	if(bin == 1)
    {
      	tell_room(TP,"%^BLUE%^The blue crystal has already been inserted!");
      	return 1;
    }
    	BLUE=counter+1;
    	counter=BLUE;
    	bin = 1;
    	color[counter]="dimly";
    	tell_room(ETP,"As "+TPQCN+" slides the blue crystal into place, you hear it "+
		"click softly.  The crystal begins to glow a %^BLUE%^dim blue.");
	if(obj=present("blue crystal",TP)) obj->remove();
	checkdone();
		return 1;
  }
  if(str == "red" || str == "red crystal")
  {
    if(rin == 1)
    {
      tell_room(TP,"%^RED%^The red crystal has already been inserted!");
      return 1;
    }
    RED=counter+1;
    counter=RED;
    rin=1;
    color[(counter)]="dimly";
    tell_room(ETP,"As "+TPQCN+" slides the red crystal into place, you hear it "+
	"click softly.  The crystal begins to glow a %^RED%^dim red.%^RESET%^");
	if(obj=present("red crystal",TP)) obj->remove();
    checkdone();
    return 1;
  }
  if(str == "green" || str == "green crystal")
  {
    if(gin == 1)
    {
      tell_room(TP,"%^GREEN%^The green crystal has already been inserted!");
      return 1;
    }
    GREEN=counter+1;
    counter=GREEN;
    gin=1;
    color[(counter)]="dimly";
    tell_room(ETP,"As "+TPQCN+" slides the green crystal into place, you hear it "+
	"click softly.  The crystal begins to glow a %^GREEN%^dim green.%^RESET%^");
	if(obj=present("green crystal",TP)) obj->remove();
    checkdone();
    return 1;
  }
  if(str == "yellow" || str == "yellow crystal")
  {
    if(yin == 1)
    {
      tell_room(TP,"%^YELLOW%^The yellow crystal has already been inserted!");
      return 1;
    }
    YELLOW=counter+1;
    counter=YELLOW;
    yin=1;
    color[(YELLOW)]="dimly";
    tell_room(ETP,"As "+TPQCN+" slides the yellow crystal into place, you hear it "+
	"click softly.  The crystal begins to glow a %^YELLOW%^dim yellow.%^RESET%^");
	if(obj=present("yellow crystal",TP)) obj->remove();
    checkdone();
    return 1;
  }
}

void checkdone()
{
  number_check(rin,gin,bin,yin); 
  if((rin + gin + bin + yin) == 4)
  {
    tell_room(ETP,"%^BOLD%^As the last crystal is slid into place, the "+
	"center white crystal begins to glow dimly as well.  The "+
	"pedestal begins to emit a soft hum as all of the crystals "+
	"raise up just slightly from the surface, and it looks as "+
	"if you could press each one.");
      present("adilon",TO)->crysin();
  }
}

void press(string str)
{  
  number_check(rin,gin,bin,yin);
  if((rin + gin + bin + yin) != 4)
  {
    tell_room(TP,"It would appear you need to insert crystals into "+
        "all four slots first.");
    return 1;
  }
  if(!str)
  {
    tell_room(TP,"You need to %^RED%^press <color> crystal%^RESET%^.");
    return 1;
  }
  if(str == "blue" || str == "blue crystal")
  {
    doit(BLUE);
    tell_room(ETP,"As "+TPQCN+" presses the blue crystal, the pattern "+
	"changes.  The white crystal now glows %^BOLD%^"+color[5]+""+
	"%^RESET%^, the blue crystal now glows %^BLUE%^"+color[BLUE]+""+
	"%^RESET%^, the red crystal now glows %^RED%^"+color[RED]+""+
	"%^RESET%^, the yellow crystal now glows %^YELLOW%^"+color[YELLOW]+""+
	"%^RESET%^, the green crystal now glows %^GREEN%^"+color[GREEN]+".");
    checkit();
    return 1;
  }
  if(str == "red" || str == "red crystal")
  {
    doit(RED);
    tell_room(ETP,"As "+TPQCN+" presses the red crystal, the pattern "+
	"changes.  The white crystal now glows %^BOLD%^"+color[5]+""+
	"%^RESET%^, the blue crystal now glows %^BLUE%^"+color[BLUE]+""+
	"%^RESET%^, the red crystal now glows %^RED%^"+color[RED]+""+
	"%^RESET%^, the yellow crystal now glows %^YELLOW%^"+color[YELLOW]+""+
	"%^RESET%^, the green crystal now glows %^GREEN%^"+color[GREEN]+".");
    checkit();
    return 1;
  }
  if(str == "green" || str == "green crystal")
  {
    doit(GREEN);
    tell_room(ETP,"As "+TPQCN+" presses the green crystal, the pattern "+
	"changes.  The white crystal now glows %^BOLD%^"+color[5]+""+
	"%^RESET%^, the blue crystal now glows %^BLUE%^"+color[BLUE]+""+
	"%^RESET%^, the red crystal now glows %^RED%^"+color[RED]+""+
	"%^RESET%^, the yellow crystal now glows %^YELLOW%^"+color[YELLOW]+""+
	"%^RESET%^, the green crystal now glows %^GREEN%^"+color[GREEN]+".");
    checkit();
    return 1;
  }
  if(str == "yellow" || str == "yellow crystal")
  {
    doit(YELLOW);
    tell_room(ETP,"As "+TPQCN+" presses the yellow crystal the pattern "+
	"changes.  The white crystal now glows %^BOLD%^"+color[5]+""+
	"%^RESET%^, the blue crystal now glows %^BLUE%^"+color[BLUE]+""+
	"%^RESET%^, the red crystal now glows %^RED%^"+color[RED]+""+
	"%^RESET%^, the yellow crystal now glows %^YELLOW%^"+color[YELLOW]+""+
	"%^RESET%^, the green crystal now glows %^GREEN%^"+color[GREEN]+".");
    checkit();
    return 1;
  }
  if(str == "white" || str == "white crystal")
  {
    doit(WHITE);
    tell_room(ETP,"As "+TPQCN+" presses the white crystal, the pattern "+
	"changes.  The white crystal now glows %^BOLD%^"+color[5]+""+
	"%^RESET%^, the blue crystal now glows %^BLUE%^"+color[BLUE]+""+
	"%^RESET%^, the red crystal now glows %^RED%^"+color[RED]+""+
	"%^RESET%^, the yellow crystal now glows %^YELLOW%^"+color[YELLOW]+""+
	"%^RESET%^, the green crystal now glows %^GREEN%^"+color[GREEN]+".");
    checkit();
    return 1;
  }
}

void checkit()
{
  if(color[1]=="brightly" && color[2]=="brightly" && color[3]=="brightly" &&
color[4]=="brightly" && color[5]=="brightly")
  {
  remove_action("press","press");
  tell_room(ETP,"%^BOLD%^As all five crystals begin to glow brightly, a beam "+
	"of light projects out from the white crystal.  A misty white "+
	"portal begins to take shape, that seems to swirl before you.");
  add_exit(ROOMS+"gem1","white");
  remove_action("restart","restart");
  present("adilon",TO)->done();
  }
}

void doit(int x)
{
  switch(x)
  {
    case 1:
      color[1]=flipit(color[1]);
      color[2]=flipit(color[2]);
      color[3]=flipit(color[3]);
      break;
    case 2:
      color[5]=flipit(color[5]);
      color[2]=flipit(color[2]);
      color[3]=flipit(color[3]);
      break;
    case 3:
      color[4]=flipit(color[4]);
      color[5]=flipit(color[5]);
      color[3]=flipit(color[3]);
      break;
    case 4:
      color[1]=flipit(color[1]);
      color[4]=flipit(color[4]);
      color[5]=flipit(color[5]);
      break;
    case 5:
      color[4]=flipit(color[4]);
      color[2]=flipit(color[2]);
      color[5]=flipit(color[5]);
      break;
  }
}

string l_crys()
{
  int x;
  string str;
  number_check(rin,gin,bin,yin);  
  x=rin + gin + bin + yin;
  if(x == 4)
  {
  return "%^BOLD%^The pedestal contains 5 crystals that stick out "+
        "from the top surface.  The center crystal is a milky "+
        "white color, that is glowing %^BOLD%^"+color[5]+"%^RESET%^"+
	  "%^BOLD%^.  Four other "+
        "crystals surround the white one, creating a plus sign.  "+
        "The red crystal is glowing %^RED%^"+color[RED]+"%^RESET%^"+
	  "%^BOLD%^, a blue crystal "+
        "is glowing %^BLUE%^"+color[BLUE]+"%^RESET%^%^BOLD%^, a yellow "+
	"crystal is glowing %^YELLOW%^"+
        ""+color[YELLOW]+"%^RESET%^, and the green crystal is glowing "+
        "%^GREEN%^"+color[GREEN]+"%^RESET%^.  The pedestal seems to "+
	"be emiting a faint humming sound.";
  }
  else
  {
    switch(x)
      {
      case 0:
        str="none";
        break;
      case 1:
        str="one";
        break;
      case 2:
        str="two";
        break;
      case 3:
        str="three";
        break;
     }
    return "%^BOLD%^The pedestal contains 5 slots that could hold "+
        "various crystals.  The center crystal is firmly attached, "+
        "and is a milky white color.  Four slots surround the "+
        "white crystal, creating plus sign.  Right now, "+
        ""+str+" of the slots contain crystals.";
  }
  
}

void number_check(int one, int two, int three, int four)
{
    if(one > 1)     { rin = 1; }
    if(two > 1)     { gin = 1; }
    if(three > 1)   { bin = 1; }
    if(four > 1)    { yin = 1; }
    return;
}

string flipit(string str)
{
  if(str == "dimly")
  {
    return "brightly";
  }
  else
  {
    return "dimly";
  }
}

void restart()
{
  color[1]="dimly";
  color[2]="dimly";
  color[3]="dimly";
  color[4]="dimly";
  color[5]="dimly";
  tell_room(ETP,"All five crystals begin to glow dimly again.");
  return 1;
}

void reset()
{
    object *living;
    ::reset();
    if(!present("adilon"))
    {
        new(MON+"adilon.c")->move(this_object());
    }
    living = all_living(TO);
    living = filter_array(living, "is_non_immortal_player", FILTERS_D);
    if(!sizeof(living))
    {    
        rin = 0;
        gin = 0;
        bin = 0;
        yin = 0;
        color = ([]);
        color[5]="dimly";
        counter = 0;
        WHITE = 5;
    }
}
