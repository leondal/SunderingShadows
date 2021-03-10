
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";

int spoken;


void create(){
  ::create();
  spoken = 0;
  set_exits(([
                "northwest":TUNNELS + "tun03",
                "northeast":TUNNELS + "tun10",
                "south":TUNNELS + "tun01",
      ]));
}

void reset() 
{
  ::reset();
  spoken = 0;
}

void enter_room()
{
  if(!present("magicmouth")&& spoken ==0)
  {
    mouthsay("Two ways to go,");
    call_out("enter2", 6);
  }
}

void enter2()
{
  mouthsay("Two ways to seek");
  mouthsay("For those who come");
  mouthsay("To the place beneath");
  call_out("enter3",1);
}

void enter3()
{
  tell_room(TO, " ");
  mouthsay("Two ways to go,");
  mouthsay("Which will you choose?");
  mouthsay("Will you win");
  mouthsay("Or will you lose?");
  call_out("enter4",1);
}

void enter4()
{
 tell_room(TO, " ");
  tell_room(TO,"The magic mouth smirks before continuing");
 tell_room(TO, " ");

  call_out("enter5",2);
}

void enter5()
{
  mouthsay("Easterly");
  mouthsay("Could be easy");
  mouthsay("But maybe west");
  mouthsay("Would be the best");
  call_out("enter6",2);
}

void enter6()
{
  tell_room(TO, " ");
  mouthsay("For the easy path");
  mouthsay("That you could tread");
  mouthsay("May wind up");
  mouthsay("With you all dead");
  call_out("enter7", 2);
}

void enter7()
{

  present("magicmouth")->remove(TO);  
  tell_room(TO, " ");

  tell_room(TO,"The magic mouth breaks into manic laughter as it slowly"
              +" fades back into the rock");
  spoken = 1;
}