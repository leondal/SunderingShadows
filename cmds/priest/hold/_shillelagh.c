// Originally : Melnmarn@ShadowGate
// ALtered by Pator@ShadowGate 10/20/95

// This spell can be cast by interactives as objects

#include <std.h>
#include <spell.h>

inherit SPELL;

create() {
	::create();
	set_spell_name("shillelagh");
	set_spell_level(1);
	set_spell_type("priest");
	set_spell_sphere("plant");
	set_target_required(0);
	set_non_living_ok(1);
}

spell_effect() {
    object ob,ob2;
    int level;
    string HIM,YOU;
	::spell_effect();

	YOU = (string)CASTER->query_name();

        if ( interactive(CASTER) )
	  {
	     set_cast_string(YOU+" prays for divine help !\n");

	     level = CASTER->query_level();
	     if(level > 20) level = 20;
	     if(!ob2 = present("staff",CASTER))
	       {
	             tell_object(CASTER, "You don't have a staff !");
		     tell_room(environment(CASTER),
			       YOU+" fails to call on a shillelagh !",
			       ({ CASTER }) );
	             return;
	       }
	     ob = new("/cmds/priest/obj/shillelagh");
	     ob->set_duration(40+(level * 10));
	     ob->set_owner(CASTER);
	     ob->set_object(file_name(ob2));
	     ob->move((CASTER));
	     CASTER->force_me("wield staff in right hand and left hand.");
	     CASTER->set_casting(4);
	   }
       // IF CALLED BY OBJECT IT IS MOVED INTO THIS ROOM
       // WHILE IT NEEDS TO HAVE A GUILD_LEVEL IT CHECKS THIS
       // FOR DURATION
       else
	 {
	   set_cast_string(YOU+" starts to glow for divinity !\n");

	   level = CASTER->query_guild_level("priest");
	   
	     if(level > 20) level = 20;
	     if(!ob2 = present( "staff", environment(CASTER) ) )
	       {
	             tell_object(CASTER, "You don't have a staff !");
		     tell_room(environment(CASTER),
			       YOU+" fails to call on a shillelagh !",
			       ({ CASTER }) );
	             return;
	       }
	     ob = new("/cmds/priest/obj/shillelagh");
	     ob->set_duration(40+(level * 10));
//	     ob->set_owner(CASTER);
	     ob->set_object(file_name(ob2));
	     ob->move((environment(CASTER)));
//	     CASTER->force_me("wield staff in right hand and left hand.");
	     CASTER->set_casting(4);
}

int help(string str){
write(
@HELP
Level  : 1st level
Sphere : Plant
Syntax : <cast shillelagh>

Shillelagh will take the casters staff, and make
it into a magically enhanced staff. The enhancements
will only last a short time, then the staff will
revert back to it's old self. Only the caster
of the spell, can wield the staff.
HELP
);
return 1;
}

