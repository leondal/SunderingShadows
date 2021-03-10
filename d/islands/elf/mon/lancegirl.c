//celestial type thing for lance
#include <std.h>
#include <daemons.h>

inherit WEAPONLESS;
object lance, owner;

void create()
{ ::create();
  set_name("Winged Woman");
  set_id(({"angel","woman","winged woman","celestial"}));
  set_short("%^BOLD%^%^WHITE%^Winged Woman%^RESET%^");
  set_long("This woman wears no clothing and has golden skin."+
  "  She has bright golden eyes that seem to glow with a"+
  " righteous fire.  Instead of arms she has two "+
  "feathered wings and her womanly parts are similarly "+
  "covered with matching white feathers.  Likewise, her "+
  "hair also consists of white feathers that go down to her shoulders.    ");
  set_race("celestial");
  set_body_type("human");
  set_gender("female");
  set_size(2);
  set_hd(20,10);
  set_level(20);
  set_hp(random(500)+100);
  set_overall_ac(-20);
  set_alignment(1);
  set_stats("intelligence",18);
  set_stats("wisdom",18);
  set_stats("strength",12);
  set_stats("charisma",20);
  set_stats("dexterity", 20);
  set_stats("constitution",12);
  setenv("MIN", "$N flies in elegantly");
  setenv("MOUT", "$N flies $D elegantly");
  set_property("magic resistance",30);
  set_property("damage resistance",2);
  set_property("magic",1);   
  set_funcs(({"sing"}));
  set_func_chance(100);
  //set_property("knock unconsious",1);
  set_damage(4,20);
  command("speech %^CYAN%^echo%^MAGENTA%^ through the area");
  
}
void set_lance(object ob, object ob2){
  lance = ob;
  owner = ob2;
}

void sing()
{  int i,align;
   object *foes;
   //if(!lance) TO->remove();
   if(!objectp(TO)) return ;
   if(!objectp(ETO)) return ;
    foes = all_living(ETO);
    foes = filter_array(foes, "is_non_immortal",FILTERS_D);
   command("say purging this area of evil");	
   tell_room(ETO,"%^ORANGE%^The woman sings a"+
   " single holy note and her whole body glows with a %^YELLOW%^golden radiance."); 
   if(ETO-> query_property("light") < 3 ) ETO->set_property("light",3);
		
  for (i = 0; i < sizeof (foes); i++){
    if(!objectp(foes[i])) continue;
	   align = foes[i]->query_alignment();
    if(align == 1 || align == 4 || align == 7) continue;
    if(!"/daemon/saving_throw_d.c"->will_save(foes[i],-30)) {
         tell_object(foes[i],
           "%^YELLOW%^Your soul burns with holy fire");
         foes[i]->set_paralyzed(5,"%^ORANGE%^You cringe in fear of your own judgement.");
         foes[i]->add_attacker(TO);
         foes[i]->cause_typed_damage(ETO, ETO->return_target_limb(),random(30), "divine");
	     
         }
  }
   return ;
}
void init(){
  ::init();
	 if(find_call_out("sing")==-1)  {
	   call_out("sing",20);
	   command("say I will purify this area.");
	   command("emote begins to glow");
	  }
  
}
void query_var(){
  return owner;
}
void struck(int damage, object weapon, object attacker, string limb) 
{
    int x;
	//if(objectp(owner)) remove();
    if(damage > 0)  { 
	 damage = damage / 2;
	 x = do_damage(limb, damage); 
	 tell_object(owner, "%^RED%^Some of the celestial's pain is transfered to you.");
	 owner->do_damage(limb, damage);
	}    
    else            { x = 0; }
    if(objectp(attacker)) { attacker->send_messages(0, weapon,limb, x, TO); }
}
void die(object ob){
	tell_room(ETO,"%^BOLD%^The woman vanishes in a blast of feathers.");
	remove();
}

