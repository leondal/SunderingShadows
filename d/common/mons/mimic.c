#include <std.h>
#include <daemons.h>
#include <money.h>

inherit MONSTER;
object ChestOb, MyTarg;
string ChestObFile, tmpShort;
int delay;

void become_this(object ob, object vic);

void create()
{
	::create();
   	add_search_path("/cmds/fighter");
   	set_gender("neuter");
    	set_alignment(9);
   	set_property("full attacks", 1);
   	set_property("swarm",1);
	delay = 0;
}

void become_this(object ob, object vic)
{
	string myshort;
	int mod, y;
	if(!objectp(TO)) return;
	if(!objectp(ob)) return;

	ChestOb = ob;
	ChestObFile = base_name(ob);

	mod = (int)ob->query_myMimicExpLevel();
	if(!mod) mod = 5;
	set_new_exp(mod, "normal");

	mod = (int)ob->query_myMimicLevel();
	if(!mod) mod = 5;

	set_id(ob->query_id());
	add_id("mimic");

	myshort = ob->query_short();

	set_name("mimic");

	set_short(myshort + " %^BOLD%^%^WHITE%^(%^BOLD%^%^RED%^ "+
	"with massive arms and rows of %^RESET%^%^WHITE%^"+
	"gleaming metal teeth%^BOLD%^%^WHITE%^ )%^RESET%^");

	set_long("%^BOLD%^%^BLACK%^This "+myshort+
	"%^BOLD%^%^BLACK%^ has %^BOLD%^%^WHITE%^"+
	"revealed%^BOLD%^%^BLACK%^ itself to truly be a %^BOLD%^%^GREEN%^"+
	"fabled mimic%^BOLD%^%^BLACK%^.  It is covered "+
	"with strange %^BOLD%^%^CYAN%^runes%^BOLD%^%^BLACK%^ "+
	"and %^BOLD%^%^CYAN%^glyphs%^BOLD%^%^BLACK%^ which you "+
	"suppose are what helps it maintain a form of life.  "+
	"Its vicous looking mouth reveals rows upon rows of "+
	"%^BOLD%^%^WHITE%^gleaming metal teeth%^BOLD%^%^BLACK%^ "+
	"and two grotesquely muscled arms have sprung out from "+
	"it - one from each end where a handle should be.  "+
	"Set into what should be the lid, are two "+
	"dark %^BOLD%^%^RED%^evil%^BOLD%^%^BLACK%^ eyes.%^RESET%^");

	set_body_type("chest");
   	set_race("mimic");
	add_limb("mouth", 0, 0, 0, 0);
	add_limb("left arm", 0, 0, 0, 0);
	add_limb("right arm", 0, 0, 0, 0);
	set_attack_limbs(({"left arm", "right arm"}));

	set_hd(mod, 1);
	set_max_hp(mod * 20 + random(35));
	set_hp(query_max_hp());

	set_size(ob->query_size());

	if(mod >= 25)
	{
		set_property("magic",1);
	}

	y = mod / 5;

	if(y) set_property("weapon resistance", (y/2));

   	set_mob_magic_resistance("average");

	set_stats("strength", 17 + y);
  	set_stats("dexterity", 14 + y);
  	set_stats("constitution", 14 + y);
   	set_stats("intelligence", 6);
   	set_stats("charisma", 6);
   	set_stats("wisdom", 6);
	set_base_damage_type("cold iron");
	//2-11 attacks
   	set_attacks_num((y+1));

	//2d7-2d14 damage
   	set_damage(2, (y+4));

	//3-10 attack bonus
	set_attack_bonus(y + 3);

	set_overall_ac(-6 - y);

	TO->move(environment(ob));
	ob->set_property("no detect", 1);
	ob->set_hidden(1);
	tmpShort = ob->query_short();
	ob->set_short(0);
	ob->move(TO);
	if(objectp(vic))
	{
		TO->force_me("kill "+vic->query_name());
		MyTarg = vic;
	}
}

void quiet_down()
{
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	if(!objectp(ChestOb))
	{
		if(!stringp(ChestObFile)) return;
		if(stringp(ChestObFile))
		{
			ChestOb = new(ChestObFile);
		}
		if(!objectp(ChestOb)) return;
	}
	ChestOb->set_short(tmpShort);
	tell_room(ETO, "%^BOLD%^%^BLACK%^With a sudden violent %^BOLD%^%^MAGENTA%^"+
	"shudder%^BOLD%^%^BLACK%^ "+ChestOb->query_short()+"%^BOLD%^"+
	"%^BLACK%^ ceases all movement and becomes mundane and "+
	"lifeless once again!%^RESET%^");
	ChestOb->set_hidden(0);
	ChestOb->set_property("no detect", -1);
	ChestOb->move(ETO);
	TO->move("/d/shadowgate/void");
	TO->remove();
}


//hoping to build a list of directions
//for our mimic to run (sans doors, no door opener)
//after a target - if the target is within 5 rooms
//of the mimic - will execute up to two of these
//directions at a time - chasing the target that
//originally disturbed it - Saide

void chase(object ob)
{
	string *cmds = ({});
	string tn;
	//tell_object(find_player("saide"), "Getting here - in void chase()");
	if(!objectp(TO))
	{
		quiet_down();
		return;
	}
	if(!objectp(ob))
	{
		quiet_down();
		return;
	}
	tn = ob->query_name();
	if(!PATHFINDER_D->far_present(ETO, tn, 5))
	{
		quiet_down();
		return;
	}
	cmds = PATHFINDER_D->findpath(ETP, environment(ob), ({}), ({}), ({}), 5, 0);
	if(!sizeof(cmds))
	{
		quiet_down();
		return;
	}
	TO->force_me(cmds[0]);
	if(present(tn, ETO))
	{
		TO->force_me("kill "+tn);
		return;
	}
	if(sizeof(cmds) > 1 && random(2))
	{
		TO->force_me(cmds[1]);
		if(present(tn, ETO))
		{
			TO->force_me("kill "+tn);
			return;
		}
	}
	delay = 6;
	return;
}

void heart_beat()
{
	::heart_beat();
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;
	//tell_object(find_player("saide"), "Mytarg = "+identify(MyTarg));
	if(!sizeof(filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D)))
	{
		if(!objectp(MyTarg))
		{
			quiet_down();
			return;
		}
		if(MyTarg->query_true_invis())
		{
			quiet_down();
			return 1;
		}
		if(objectp(MyTarg) && !present(MyTarg->query_name(), ETO))
		{
			//tell_object(find_player("saide"), "Getting here...");
			if(random(20))
			{
				//tell_object(find_player("saide"), "Getting here (delay)");
				if(delay)
				{
			//tell_object(find_player("saide"), "Getting here (delay - inside)");
					delay--;
					return;
				}
				else
				{
					//tell_object(find_player("saide"), "Getting here (chase)");
					chase(MyTarg);
					return;
				}
			}
			else quiet_down();
			return;
		}
	}
	return;
}

void die(object ob)
{
	object treasure_ob;
	mapping MyStuff;
	string *MyStuffKeys, tmp;
	int flag, x, amt;
	if(!objectp(TO)) return;
	if(!objectp(ETO)) return;


	tell_room(ETO, "%^BOLD%^%^BLACK%^The mimic "+
	"bursts open with a final %^BOLD%^%^YELLOW%^"+
	"s%^BOLD%^%^GREEN%^i%^BOLD%^%^YELLOW%^ck"+
	"%^BOLD%^%^GREEN%^e%^BOLD%^%^YELLOW%^n"+
	"%^BOLD%^%^GREEN%^i%^BOLD%^%^YELLOW%^ng "+
	"%^BOLD%^%^RED%^ROAR%^BOLD%^%^BLACK%^ and "+
	"its treasure horde spills out on the ground!%^RESET%^");

	if(!objectp(ChestOb))
	{
		if(!stringp(ChestObFile))
		{
			flag = 1;
		}
		if(stringp(ChestObFile))
		{
			ChestOb = new(ChestObFile);
			if(!objectp(ChestOb)) flag = 1;
		}
	}
	if(objectp(ChestOb))
	{
		MyStuff = ChestOb->query_myMimicTreasure();
		if(!mapp(MyStuff)) flag = 1;
	}
	if(flag)
	{
		treasure_ob = new("/std/obj/coins");
     		treasure_ob->set_money("gold", 1000 + random(500));
     		treasure_ob->move(ETO);
	}
	else
	{
		MyStuffKeys = keys(MyStuff);
		for(x = 0;x < sizeof(MyStuffKeys);x++)
		{
			if(member_array(MyStuffKeys[x], HARD_CURRENCIES) != -1)
			{
				amt = MyStuff[MyStuffKeys[x]];
				if(!intp(amt)) continue;
				treasure_ob = new("/std/obj/coins");
				treasure_ob->set_money(MyStuffKeys[x], amt);
				treasure_ob->move(ETO);
				continue;
			}
			else
			{
				tmp = MyStuffKeys[x];
				if(strsrch(tmp, ".c") == -1) tmp = tmp + ".c";
				if(!file_exists(tmp)) continue;
				amt = MyStuff[MyStuffKeys[x]];
				if(!intp(amt))
				{
					new(tmp)->move(ETO);
					continue;
				}
				while(amt)
				{
					new(tmp)->move(ETO);
					amt--;
					continue;
				}
				continue;
			}
		}
	}
	TO->move("/d/shadowgate/void");
	::die(ob);
}
