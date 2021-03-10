#include <std.h>

#define ob TP
#define STR ob->query_stats("strength")
#define CON ob->query_stats("constitution")
#define DEX ob->query_stats("dexterity")
#define CHA ob->query_stats("charisma")
#define INT ob->query_stats("intelligence")
#define WIS ob->query_stats("wisdom")

void contact_poison();
void wall_darts();

void contact_poison() {
  int chance, dmg;
  dmg=random(25)+15;
  chance=random(50);
  if(DEX>=6) chance+=10;
  if(DEX>=12) chance+=10;
  if(DEX>=18) chance+=10;
  write("%^BOLD%^Your foot hits a tripwire and a fine mist begins to enter the room.%^RESET%^");
  if(chance > random(100)) {
    write("%^BOLD%^You dive through the doorway, narrowly avoiding the mist!%^RESET%^");
    say("%^BOLD%^"+ob->query_cap_name()+" dives through the doorway and avoids the mist!%^RESET%^");
  } else {
    write("%^RED%^The mist engulfs you and you feel poison course through your veins!%^RESET%^");
    say("%^RED%^"+ob->query_cap_name()+" is engulfed by the mist!%^RESET%^");
    ob->cause_typed_damage(ob, "torso", dmg, "untyped");
  }
  return 1;
}

void wall_darts() {
  int chance, number;
  chance=random(50);
  number=random(20)+15;
  if(DEX>=6) chance+=5;
  if(DEX>=12) chance+=5;
  if(DEX>=18) chance+=10;
  write("%^BOLD%^You feel your foot hit a tripwire!%^RESET%^");
  if(chance > random(100)) {
    write("%^BOLD%^You jump through the doorway, avoiding the wall darts!%^RESET%^");
    say("%^BOLD%^"+ob->query_cap_name()+" ducks past the wall darts!%^RESET%^");
  } else {
    write("%^RED%^You are hit by "+number+" wall darts!%^RESET%^");
    say("%^RED%^"+ob->query_cap_name()+" is hit by the wall darts!%^RESET%^");
    ob->cause_typed_damage(ob, "torso", number, "piercing");
  }
  return 1;
}
