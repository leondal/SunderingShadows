// Mirror Image

#include <spell.h>
#include <magic.h>

inherit SPELL;

int numclone, num, num2, i, vanish, *clonehp, waittime;
object caster, target, tempob, *casters, *inv, *tempinv, *objinv;
mapping cloneinv;

void check(int num);
void reinventory();
object *cleansed_array();
void randomize();

void create()
{
    ::create();
    set_spell_name("mirror image");
    set_spell_level(2);
    set_spell_type("wizard");
    set_spell_sphere("illusion_phantasm");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(0);
//  set_xp_bonus(5);
tempinv = ({});
}

// First get 2 to 8 clones of the caster, all illusions that are set
// up exactly like caster in appearance.  Then give all the same
// exact inventory.  Then mix the clones and the caster up and start
// the check routine.
void spell_effect()
{
    caster=CASTER;
    place=PLACE;
    clevel=CLEVEL;
    waittime=3 * clevel;
    numclone=2+random(4)+to_int(clevel/3);
    spell_successful();
    casters=allocate(numclone);
    cloneinv=allocate_mapping(numclone);
    for(num=0;num=sizeof(casters)-1;num++)
    {
	casters[num]=new("/d/magic/mon/clone.c");
	casters[num]->set_cap_name(caster->query_cap_name());
	casters[num]->set_name(caster->query_name());
	casters[num]->set_id( ({ caster->query_name() }) );
        casters[num]->set("short", caster->query_short() );
        casters[num]->set("long", caster->query_long() );
	casters[num]->set_gender(caster->query_gender());
	casters[num]->set("race", caster->query_race());
	casters[num]->set_body_type(caster->query_body_type());
	casters[num]->set("aggressive",1);
	casters[num]->set_size(caster->query_size());
	casters[num]->set_stats("strength",
	    caster->query_stats("strength"));
	casters[num]->set_stats("charisma",
	    caster->query_stats("charisma"));
	casters[num]->set_stats("constitution",
	    caster->query_stats("constitution"));
	casters[num]->set_stats("dexterity",1);
	casters[num]->set_stats("intelligence",1);
	casters[num]->set_stats("wisdom",1);
	casters[num]->set_max_hp(caster->query_max_hp());
        casters[num]->set_hp(caster->query_hp());
	casters[num]->set_wielding_limbs(
	    caster->query_wielding_limbs());
        casters[num]->set_property("illusion",1);
	caster->add_follower(casters[num]);
	inv=caster->all_inventory();
        tempinv=allocate(sizeof(inv));
	for(num2=0;num2<=sizeof(inv);num2++)
	{
	    tempinv[num2]=new(file_name(inv[num2]));
            tempinv[num2]->set_property("illusion",1);
	    tempinv[num2]->move(casters[num]);
	    if(inv[num2]->query_worn())
	    {
		casters[num]->force_me("wear "+
		    inv[num2]->query_name());
	    }
	    if(inv[num2]->query_wielded())
	    {
		casters[num]->force_me("wield "+
		    inv[num2]->query_name()+" "+
		    inv[num2]->query_limb_string());
	    }
	}
	cloneinv[casters[num]]=tempinv;
        clonehp[num]=casters[num]->query_hp();
    }
    num=0;
    randomize();
    call_out("check", ROUND_LENGTH, 0);
}

// Perform check for needed updates and spell expiration every round.
void check(int num)
{
    if(!caster)
        dest_effect();
    if( (int)caster->query_hp() < 1 )
        dest_effect();
    vanish=0;
    for(num2=0;num2 <= sizeof(casters)-1;num2++)
    {
	if( (casters[num2] != caster) && (casters[num2]) )
	{
	    for(i=0;i<=(sizeof(cloneinv[casters[num2]])-1);
		num2++)
	    {
		if(tempob=cloneinv[casters[num2]][i])
		{
		    if(environment(tempob) != casters[num2])
		    {
		    tempob->move(casters[num2]);
		    vanish=1;
		    }
		}
	    }
	    if(vanish)
	    {
		casters[num2]->move("/d/shadowgate/void.c");
		casters[num2]->remove();
	    }
	}
    }
    casters=cleansed_array();
    if(num++ >= waittime || (casters == ({}) ) )
    {
        dest_effect();
    }
    else
    {
	call_out("check", ROUND_LENGTH, num);
    }
    reinventory();
    randomize();
}


// For restocking the clone's inventory according to the latest
// inventory of the caster.
void reinventory()
{
    for(num=0;num=sizeof(casters)-1;num++)
    {
	casters[num]->set_short( ({ caster->query_short() }) );
        casters[num]->set("long", caster->query_long() );
	casters[num]->set_gender(caster->query_gender());
	casters[num]->set("race", caster->query_race());
	casters[num]->set_body_type(caster->query_body_type());
	casters[num]->set_size(caster->query_size());
	casters[num]->set_stats("strength",
	    caster->query_stats("strength"));
	casters[num]->set_stats("charisma",
	    caster->query_stats("charisma"));
	casters[num]->set_stats("constitution",
	    caster->query_stats("constitution"));
	casters[num]->set_max_hp(caster->query_max_hp());
        casters[num]->set_hp(caster->query_hp());
	casters[num]->set_wielding_limbs(
	    caster->query_wielding_limbs());
	for(num2=0;num2<=sizeof(cloneinv[casters[num]]);num2++)
	{
            objinv=cloneinv[casters[num]];
	    objinv[num2]->move("/d/shadowgate/void.c");
	    objinv[num2]->remove();
	}
	inv=caster->all_inventory();
	for(num2=0;num2<=sizeof(inv);num2++)
	{
	    tempinv[num2]=new(file_name(inv[num2]));
	    tempinv[num2]->move(casters[num]);
	    if(inv[num2]->query_worn())
	    {
		casters[num]->force_me("wear "+
		    inv[num2]->query_name());
	    }
	    if(inv[num2]->query_wielded())
	    {
		casters[num]->force_me("wield "+
		    inv[num2]->query_name()+" "+
		    inv[num2]->query_limb_string());
	    }
	}
	cloneinv[casters[num]]=tempinv;
        clonehp[num]=casters[num]->query_hp();
    }
}

// Removes any hit illusions, for they vanish instantly when
// hit, and they will not be needed anymore in the array of clones,
// or their inventory array.
object *cleansed_array()
{
    object *temp;
    temp=({});
    for(i=0;i <= sizeof(casters)-1;i++)
    {
	if(casters[num])
	{
	    temp += ({ casters[num] });
	}
	else
	{
	    map_delete(cloneinv, casters[num]);
	}
    }
    return temp;
}

// Throws an array of objects into a room that returns them back in a
// different order.
void randomize()
{
    caster->set_attackers( ({}) );
    for(i=0;i=sizeof(casters)-1;i++)
    {
	casters[i]->move("/d/magic/room/randroom.c");
    }
    environment(casters[0])->randomize(TO, casters+({caster}) );
}

// Remove all images and their equipment when the spell runs out
// or they're dispelled.
void dest_effect()
{
    ::dest_effect();
    if(find_call_out("check"))
        remove_call_out("check");
    for(num=0;num <= sizeof(casters)-1;num++)
    {
	if( (casters[num] != caster) && (casters[num]) )
	{
	    for(num2=0;num2<=(sizeof(cloneinv[casters[num]])-1);
		num2++)
	    {
		if(cloneinv[casters[num]][num2])
		{
		    cloneinv[casters[num]][num2]->move(casters[num]);
		}
	    }
	    casters[num]->move("/d/shadowgate/void.c");
	    casters[num]->remove();
	}
    }
    destruct(TO);
}

int help()
{
    write(
@EndText
Syntax: cast mirror image

	Mirror image will create multiple images of the caster.
These images are illusions that are indistinguishable from the
caster himself.  The caster is randomly mixed in with the images,
so no one knows which is the real caster.  When an image is hit,
it will disappear.  The images will shift around the caster every
round.  If the caster is hit, he'll be mixed in the next round
with the remaining images.

Material component required:

None

EndText
    );
    return 1;
}
