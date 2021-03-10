// Pator@ShadowGate
// Jan 10 1996

#include <priest.h>

inherit SPELL;

string pick(string *limbs,string *wielding, int which, int number);
int calc_damage(int clevel);
string d_string(int amount);

string query_cast_string()
{
	string cast;
	if (interactive(CASTER))
	  { cast = YOU+" prays to Snijkers the God of the butchers !!\n"; }
	else
	  { cast = YOU+" calls for Snijkers the God of the butchers !!\n"; }
	return cast;
}

void create()
{
	::create();
	set_spell_name("limb attack");
	set_author("pator");
	set_spell_level(2);
	set_spell_type("priest");
	set_spell_sphere("combat");
	set_target_required(1);
	set_somatic_comp();
	set_verbal_comp();
        set_immunities( ({ "spell_immunity" }) );
	set_xp_bonus(30);
}

spell_effect()
{
string *limbs,*wielders,limb,message;
int which_limb,clevel,damage,number;
        clevel = CLEVEL;

	if (interactive(target) || living(target))
	{
	    // Find all limbs of the target
	  limbs = target->query_limbs();
	    // Find all wielding limbs of the target
	  wielders = target->query_wielding_limbs();
	    // Pick the limb to be damaged
	  number = sizeof(limbs);
	  number -= sizeof(wielders);
	  which_limb = random(number);
	  limb = pick(limbs, wielders, which_limb, number);
	    // Compute the damage to that limb
          damage  = calc_damage(clevel);
	  message = d_string(damage);
	    // Tell the room the news, the C & T aren't forgotten !
	  tell_object(caster,
	       "%^BOLD%^%^RED%^You hurt "+HIM+"'s "+limb+" "+
               message+"you jerk at it!%^RESET%^");
	  tell_object(target,"%^BOLD%^%^RED%^"
	       +YOU+" hurts your "+limb+" "+
               message+MY_PERS+" jerks at it!%^RESET%^");
          tell_room(HERE,"%^BOLD%^%^RED%^"
               +YOU+" hurts "+HIM+"!!\nHe jerks at "+MINE+" "+limb+"!%^RESET%^",
               ({ caster, target}) );
            // Do the actual damage to the limb
          damage_targ(target,limb,damage);
          spell_successful();
	  }
         else
          { 
            tell_object(caster,"%^CYAN%^"
               "You fail in attacking "+HIM+" !");
            tell_object(target,"%^CYAN%^"
               +YOU+" fails in attacking you !!");
            tell_room(HERE,"%^CYAN%^"
               +YOU+" fails in attacking "+HIM+" !!",
               ({ caster, target }) );
          }
          dest_effect();
}

void dest_effect()
{
  ::dest_effect();
    destruct(this_object());
}


// Pick a limb from the array limbs and look if it isn't a wielding
// limb. If it is not, return it. If it is use an other limb
string pick(string *limbs,string *wielding, int which, int number)
{
  string limb;
  if ( which > number )
    which = 0;
  limb = limbs[which];
  if (member_array(limb,wielding) == -1)
    { return limb; }
  else
    { which += 1;
      return pick(limbs, wielding, which,number); }
}


// Compute the damage to the limb
int calc_damage(int clevel)
{
  int temp,power,damage;
          power = caster->query_stats("strength");
	  temp = ( ( 100 - (25-power)*4 ) - 1 );
	  if (clevel < 6) clevel = 6;
	  if (clevel > 20 && !wizardp(caster)) clevel = 20;
	  temp *= clevel;
          temp = to_int( temp / 10 );
	  switch (temp)
	    {
	      case  0..25 : damage = 5   ; break;
	      case 26..40 : damage = 10   ; break;
	      case 41..60 : damage = 15   ; break;
	      case 61..75 : damage = 20   ; break;
	      case 76..99 : damage = 25   ; break;
	      default     : damage = temp-15  ; break;
	    }
  return damage;
}

string d_string(int amount)
{
  string damage;
  switch(amount)
  {
    case  0..25 : damage = "badly as "       ; break;
    case 26..40 : damage = "very badly as "  ; break;
    case 41..60 : damage = "severly as "     ; break;
    case 61..75 : damage = "heavily as "     ; break;
    case 76..99 : damage = "till it almost comes off as " ; break;
    default     : damage = "so that it is useless as ";break;
  }
  return damage;
}
int help(string str)
{
write(
@HELP
Level  : 2nd level
Sphere : Combat
Syntax : <cast limb attack on [%^BOLD%^%^CYAN%^living%^RESET%^] >

This spell will attack a non-wielding limb of the target.
You will try to tear that limb of. So your strength is very 
important hre as is your guild level for extra strength.
HELP
);
return 1;
}
