//      Sleep
//      Thorn@Shadowgate
//      2/14/95
//      Wizard Spells
//      sleep.c

mapping prev_hp;
string name;

string query_sphere() { return "enchantment/charm"; }

void do_spell(object caster, string targ) {
  object target;
  string *ret, spell_name;
  mapping components;
  int mp_req,x;
  spell_name = "sleep";
  components = ([ "rose petals" : 1,]);
  if(!caster) return 0;
  seteuid(getuid());
  mp_req = "/daemon/magic_d"->query_spell_cost(2,caster->query_sphere(),query_sphere());
  if((int)caster->query_mp() < mp_req) {
    tell_player(caster, "Your magic powers are too weak to cast that spell.\n");
    return 1;
  }
  if(!"/daemon/magic_d"->can_cast(caster,1,"wizard", spell_name, components)) {
    tell_player(caster, "You cannot cast that spell.\n");
	return 1;
  }
  if(caster->query_disable()) {
    write("You are still recovering from the last spell.");
    return 1;
  }
  prev_hp = ([]);
  write("You begin to cast the spell!");
  caster->set_mp((int)caster->query_mp() - mp_req);
  caster->set_casting(1);
  say(this_player()->query_cap_name()+" raises "+this_player()->query_possessive()+" hands in the air and begins to cast a spell.");
  caster->set_disable(7);
  call_out("do_real_spell",7,caster,target);
  return 1;
}

void test(object target, int hp) {
	int hp1, hp0;
	
	if(!target) return;
	if(hp) prev_hp[name] = hp;
	hp1 = target->query_hp();
	hp0 = prev_hp[name];
	if(hp1 < hp0) { 
		tell_player(find_player("thorn"), "Test() has detected less hp.\n");
		tell_player(find_player("thorn"), "hp0 = "+hp0+", hp1 = "+hp1+".\n");
		target->remove_paralyzed();
		tell_player(target, "You are awakened by a successful attack on you!\n");
		return;
	}
	else if(hp1 > hp0) {
		tell_player(find_player("thorn"), "Test() has detected more hp.\n");
		tell_player(find_player("thorn"), "hp0 = "+hp0+", hp1 = "+hp1+".\n");		
		prev_hp[name] = hp;
		call_out("test", 7, target);
	}
	else {
		tell_player(find_player("thorn"), "Test() has defaulted.\n");
		tell_player(find_player("thorn"), "hp0 = "+hp0+", hp1 = "+hp1+".\n");
		call_out("test", 7, target);
	}
}
	
	
void do_real_spell(object caster, object target) {
  int levelmod, casterlevel, x, y, effect, temp, time;
  int hp;
  int max_hd, counter;
  object *prospective, target2;

  if(caster->query_spell_interrupted()) {
    tell_player(caster,"Your spell is disrupted by the monster's attack!\n");
    caster->set_spell_interrupted(0);
    return 1;
  }
  casterlevel = (int)caster->query_guild_level("mage");
  time = casterlevel*35;
  if(!casterlevel)
    casterlevel = (int)caster->query_guild_level("illusionist");
  if(!casterlevel) {
    tell_player(caster,"Wait, you're not a magic user!\n");
    return 1;
  }
  tell_player(caster,"You cast Sleep.\n");
  tell_room(environment(caster),caster->query_cap_name()+" throws a few rose petals in the air!\n", ({ caster }) );

// Variable assignments for spell effect.
  prospective = all_inventory(environment(caster));
  counter = 0;
  time = casterlevel*10;
  max_hd = ((int)"/daemon/dice_d"->roll_dice(4)) + ((int)"/daemon/dice_d"->roll_dice(4));
  
// Loop checks checks for valid target and then performs the effect
// on it.
	for(x=0;x<sizeof(prospective);x++) {
  		if(counter >= max_hd) break;
  		if(!living(prospective[x])) continue;
		target2 = prospective[x];
		if(target2 == caster) continue;
		tell_player(target2, "You suddenly become drowsy and fall asleep.\n");	
		target2->set_paralyzed(time, "You are asleep!\n");
           name = target2->query_name();
		hp = target2->query_hp();
		test(target2, hp);
		counter = counter + target2->query_level();
	}  
	caster->set_casting(0);
}

int help() {
  write( @EndText
Syntax: cast sleep

	When a wizard casts a "sleep" spell, he causes a 
comatose slumber to come upon one or more creatures
(other than undead and those specifically excluded from
the spell's effects).  The number of creatures affected 
by the spell is a function of the hit dice of the monsters
in the spell's effect.  The spell effects 2d4 Hit Dice of
monsters.  Monsters with 4 HD + 3hp are immune from the 
spell.
	Wounding sleepers will cause them to awaken, but 
normal noise around them will not.

Material component required:

rose petals (1 used per casting)

EndText
  );
  return 1;
}
