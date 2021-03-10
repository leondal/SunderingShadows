//  Standard speaker type person
//  by Kriton@Emerald MUD
//  A monster who recites an entire speach in order as too make
//  sense unlike a random jumble of chats.

inherit "std/monster";

void set_speach(string *speach);
void pause_between(int x);

string *__speach;
int last_part, pause;
int __left;

void create()   {
  ::create();
  last_part = 0;
  __speach = ({ });
  __left = 0;
  pause = 0;
}

void heart_beat()    {
  ::heart_beat();
  if(__left >= 1)   {
    __left -= 1;
    return;
  }
  if(sizeof(__speach) == 0) return;
  if(__speach[last_part] == "pause")   {
    last_part++;
    return;
  }
  say(__speach[last_part]);
  if(last_part == (sizeof(__speach) - 1)) last_part = 0;
    else last_part++;
  if(__left == 0 && last_part == 0 && pause > 0)   {
    __left = pause;
  }
}

void set_speach(string *speach)   {
  __speach = speach;
}

void pause_between(int x)    {
  __left = x;
  pause = x;
}
