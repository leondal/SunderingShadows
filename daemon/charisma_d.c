//NOT ACTIVELY USED

// Charisma Daemon, Version 1.0
// Garrett
// Begun 15:23 on December 18th, 2001 (Anno Domini).
// Interface function section described below here.
#include <std.h>
#include <daemons.h>

#include "/daemon/charisma_d.h"
inherit DAEMON;

// I will use intject as when I expect either an integer or an
// object that has a query_statistic("charisma") on it. I'll try
// to convert from a string or other strangeness, but I can not
// promise anything. 

int query_charisma_bonus(mixed intject);

// Okay, this is a special case. REALLY pass the object as the
// patron for this function, as then you're going to allow all
// nifty sorts of factors to come into play (race, sex, charisma)
// as well as the race of the vendor, so I really want two
// objects here, but I'll still try and take other things.

int query_percent_adjustment(mixed shopper, mixed vendor);

// This next function should also be run with two objects, so
// races can be taken into account as well as other biases that
// we might figure out might happen between players.
// May be useful in creationg followers / hirelings / Thorn's
// Thorn's react command?

int query_effective_reaction_adj(mixed viewer, mixed viewed);

// defines DEFAULT as well as _RACE ([ "viewedrace":mod, DEFAULT:mod])
// Mod goes from -10 (abject hatred) to +10 (Perfectly fine)
// 
// Racial Preferences Table as per the 1st Edition PHB
// Please do not change, this is for REFERENCE of whoever touches
// this code after me - With love - Garrett.

// 
//                                      Racial Stereotype
//              
//                 1  2  3  4  5  6  7  8  9  A  B  C  D  E  F  G  H  I  J  K 
//                 -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
// R 1> Half-Drow  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H
// A 2> Drow       H  A  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H  H
// C 3> Dwarf      H  H  P  A  G  N  G1 H  N
// E 4> Elf        H  H  A  P  T  G  T  A  H
// S 5> Gnome      H  H  G  T  P  T  G  H  N
//   6> Half-Elf   H  H  N  P  T  P  N  A  T
//   7> Halfling   H  H  T2 T3 T  N  P  N  N
// O 8> Half-Orc   H  H  H  A  H  A  N  P  T
// f 9> Human      H  H  N  N  N  T  N  N  P
//   A> Orc        H  H                       H5 T4 N  N                    T
// V B> Goblin     H  H                                                     T
// I C> Hobgoblin  H  H                                            
// E D> Gnoll      H  H                                             
// W E> Wemic      H  H                                             
// E F> Ogre       H  H                                              
// R G> OgreMage   H  H                                             
//   H> Voadkyn    H  H                                            
//   I> Firbolg    H  H                                             
//   J> Beastman   H  H                                             
//   K> Bugbear    H  H                    
//   ************************** Key ****************************************
//   
//   P=Preferred, G=Goodwill, T=Tolerant, N=Neutral, A=Antipathy, H=Hatred.
//   
//   G1: Tallfellows and Stouts are regarded by dwarves as Good. Other
//       halflings are regarded with tolerance.
//   T2: Stouts regard dwarves with Goodwill, All other subraces are Tolerant
//       of them.
//   T3: Only Tallfellows regard Elves with Goodwill, others are Tolerant of
//       them.

int reference_stereotype(mixed viewer, mixed  percieved){
return fnord;
}

int lookup_maximum_num_henchmen(mixed value) {

  int charisma;
  object ob
  if (objectp(value)) {
    ob=value;
    charisma = ob->query_base_stats("charisma")
  } else if (intp(value)) {
    charisma = value;
  } else {
    return 0;
  }
  switch (charisma) {
  case 1:
    return 0;
  case 2..4:
    return 1;
  case 5..6:
    return 2;
  case 7..8:
    return 3;
  case 9..11:
    return 4;
  case 12..13:
    return 5;
  case 14:
    return 6;
  case 15:
    return 7;
  case 16:
    return 8;
  case 17:
    return 10;
  case 18:
    return 15;
  case 19:
    return 20;
  case 20:
    return 25;
  case 21:
    return 30;
  case 22:
    return 35;
  case 23:
    return 40;
  case 24:
    return 45;
  case 25:
    return 50;
  default:
    return 0;
  }
}

int lookup_loyalty_base(mixed value) {
  int charisma;
  object ob
  if (objectp(value)) {
    ob=value;
    charisma = ob->query_base_stats("charisma")
  } else if (intp(value)) {
    charisma = value;
  } else {
    return -15;
  }
  switch (charisma) {
  case 0:
    return -15;
  case 1:
    return -8;
  case 2:
    return -7;
  case 3:
    return -6;
  case 4:
    return -5;
  case 5:
    return -4;
  case 6:
    return -3;
  case 7:
    return -2;
  case 8:
    return -1;
  case 9..13:
    return 0;
  case 14:
    return 1;
  case 15:
    return 3;
  case 16:
    return 4;
  case 17:
    return 6;
  case 18:
    return 8;
  case 19:
    return 10;
  case 20:
    return 12;
  case 21:
    return 14;
  case 22:
    return 16;
  case 23:
    return 18;
  case 24:
    return 20;
  case 25:
    return 25;
  default:
    return -10;
  }
}

int lookup_reaction_adjustment(mixed value) {
  int charisma;
  object ob
  if (objectp(value)) {
    ob=value;
    charisma = ob->query_base_stats("charisma")
  } else if (intp(value)) {
    charisma = value;
  } else {
    return -15;
  }
  switch (charisma) {
  case 0:
    return -15;
  case 1:
    return -7;
  case 2:
    return -6;
  case 3:
    return -5;
  case 4:
    return -4;
  case 5:
    return -3;
  case 6:
    return -2;
  case 7:
    return -1;
  case 8..12:
    return 0;
  case 13:
    return 1;
  case 14:
    return 2;
  case 15:
    return 3;
  case 16:
    return 5;
  case 17:
    return 6;
  case 18:
    return 7;
  case 19:
    return 8;
  case 20:
    return 9;
  case 21:
    return 10;
  case 22:
    return 11;
  case 23:
    return 12;
  case 24:
    return 13;
  case 25:
    return 14;
  default:
    return -10;
  }
}