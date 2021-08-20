#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SHAPESHIFT;

//Attack interval to perform these moves
#define SWIPE_COUNT  5  //Every X claws is a swipe
#define SWEEP_COUNT  5  //Every X tails is a sweep
#define BREATH_COUNT 8  //Every X bites is a breath
#define DEATH_COUNT  9

int breath_count,
    swipe_count,
    sweep_count,
    death_count;

//Prototyping    
void breath_attack(object player, object target, int clevel);
void swipe_attack(object player, object target, int clevel);
void sweep_attack(object player, object target, int clevel);

// all of the functions set in create below need to be there so it doesn't bug when trying to shapeshift -Ares
// when making a new shape, be sure to include those functions or it'll fall back to the defaults
void create()
{
    ::create();

    set_attack_limbs( ({ "maw","right claw","left claw","tail" }) );
    set_new_damage_type("piercing");    
    set_limbs( ({ "maw","head","torso","right claw", "left claw", "right arm","right arm","left leg","left rear claw","right leg","right rear claw","tail","right wing","left wing" }) );
    set_attack_functions(([ "maw" : (:TO,"bite_attack":), "right claw" : (:TO,"claw_attack":), "left claw" : (:TO,"claw_attack":), "tail" : (:TO,"tail_attack":) ]));
    set_ac_bonus(-20); // ac bonus is different from the other bonuses because of the way ac is calculated with different body types -Ares
    set_base_attack_num(4); 
    set_castable(0);
    set_can_talk(0);
    set_shape_race("dragon");
    set_shape_language("draconic");
    set_shape_profile("druid_dragon_999"); // needs to be something the player is unlikely to name one of their profiles when disguise goes in
    set_shape_bonus("perception",4);
    set_shape_bonus("survival",4);
    set_shape_bonus("sight bonus",4);
    set_shape_bonus("damage bonus",5);
    set_shape_bonus("attack bonus",5);
    set_shape_bonus("damage resistance",20);
    set_shape_bonus("magic resistance",20);
    set_shape_height(200+random(100));
    set_shape_weight(11000+random(5000));
    set_shape_mastery_feat("impale");
}

string * query_subraces() {
    return ({ "dragon" });
}

// custom descriptions here, override this function
int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("stands tall and deadly, covered in iron-hard scales from "+obj->QP+" horn "
        "covered head to "+obj->QP+" long tail.  A ridge of spines runs all the way down "+obj->QP+" back.  "
        ""+obj->QP+" are folded at "+obj->QP+" sides.  "+obj->QS+"'s clawed hands are easily the size of "
        "an ogre's fists.  Keenly intelligent eyes peer out at the world with deadly intent.");

    obj->setDescriptivePhrase("deadly $G $R");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in lumbers in");
    obj->force_me("message out lumbers off to the $D");

    return 1;
}

// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^GREEN%^You turn your mind out to the wilds as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^BOLD%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BLUE%^Your senses heighten, you can feel the pulse of the world, smell countless scents, "
        "you can taste the very air.  You feel centuries of intelligence pouring into your essence and feel the sensation "
        "of invulnerability as iron-hard scales cover your entire form.  You flap your wings and roar.  You are DRAGON!");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^YELLOW%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, now stands a DRAGON!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^BOLD%^You relax your focus on the natural world.");
    tell_object(obj,"%^RESET%^%^BLUE%^You can feel a tinge of remose as you feel your draconic form slipping away.");
    tell_object(obj,"%^RESET%^%^GREEN%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your own body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, shrinking and quickly loosing scales!",obj);
    tell_room(environment(obj),"%^RESET%^%^GREEN%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);
    
    return 1;
}

int can_cast() 
{ 
    if(!objectp(query_owner())) { return 0; }
    if(FEATS_D->usable_feat(query_owner(),"wild spellcraft")) { return 1; }
    return can_cast_spells; 
}

int bite_attack(object player, object target)
{
    object room;
           
    int dice,
        level;
    
    if(!player || !target)
        return 0;
       
    level = player->query_guild_level("druid");
    
    level += FEATS_D->usable_feat(TP,"savage instincts i") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts ii") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts iii") * 2;
    
    if(FEATS_D->usable_feat(player,"perfect predator") && !random(3))
    {
        level += 2;
        player->add_hp(10 + roll_dice(level, 4));
    }
    
    set_new_damage_type("piercing");
    
    breath_count++;
    death_count++;
    
    if(breath_count >= BREATH_COUNT)
        breath_attack(player, target, level * 2);
    if(death_count >= DEATH_COUNT)
        death_attack(player, target, level);
        
    if(random(3))
        return roll_dice(1, 6);
    
    return roll_dice(1 + (level / 3), 6);   
}

int claw_attack(object player, object target)
{
    object room;
           
    int dice,
        level;
    
    if(!player || !target)
        return 0;
   
    level = player->query_guild_level("druid");
    
    level += FEATS_D->usable_feat(TP,"savage instincts i") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts ii") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts iii") * 2;
    
    if(FEATS_D->usable_feat(player,"perfect predator") && !random(3))
    {
        level += 2;
        player->add_hp(10 + roll_dice(level, 4));
    }
    
    set_new_damage_type("piercing");
    
    swipe_count++;
    
    if(swipe_count >= SWIPE_COUNT)
        swipe_attack(player, target, level);
    
    if(random(3))
        return roll_dice(1, 4);
    
    return roll_dice(1 + (level / 3), 6);
}

int tail_attack(object player, object target)
{
    object room;
           
    int dice,
        level;
    
    if(!player || !target)
        return 0;
   
    level = player->query_guild_level("druid");
    
    level += FEATS_D->usable_feat(TP,"savage instincts i") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts ii") * 2;
    level += FEATS_D->usable_feat(TP,"savage instincts iii") * 2;
    
    if(FEATS_D->usable_feat(player,"perfect predator") && !random(3))
    {
        level += 2;
        player->add_hp(10 + roll_dice(level, 4));
    }
    
    set_new_damage_type("bludgeoning");
    
    sweep_count++;
    
    if(sweep_count >= SWEEP_COUNT)
        sweep_attack(player, target, level);

    if(random(3))
        return roll_dice(1, 6);
    
    return roll_dice(1 + (level / 3), 6);
}

void breath_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    breath_count = 0;
    
    if(player->query_property("negative energy affinity"))
    {
        tell_object(player,"%^CYAN%^BOLD%^You inhale a deep breath of air, feeling the ball of ice deep inside of you!");
        tell_room(room,"%^CYAN%^BOLD%^"+player->QCN+"'s chest swells with a deep breath of air!",player);
        tell_object(player,CRAYON_D->color_string("You open your mouth and unleash the chill of ice cold breath on your foes!", "ice blue"));
        tell_room(room,CRAYON_D->color_string(player->QCN+"'s mouth opens and a withering torrent of frost pours forth!", "ice blue"),player);
    }
    else
    {
        tell_object(player,"%^ORANGE%^You inhale a deep breath of air, feeling the spark of ignition deep inside of you!");
        tell_room(room,"%^ORANGE%^"+player->QCN+"'s chest swells with a deep breath of air!",player);
        tell_object(player,"%^RED%^You open your mouth and unleash the fury of dragon fire on your foes!");
        tell_room(room,"%^RED%^"+player->QCN+"'s mouth opens and a withering torrent of fire pours forth!",player);
    }
    
    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers; 
    
    dam = roll_dice(clevel, 10);  
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
        {
            tell_object(player,"%^MAGENTA%^"+ob->QCN+" is able to dive away at the last instant, avoiding most of the breath!");
            tell_object(ob,"%^MAGENTA%^You dive away at the last instant, avoiding most of the breath!");
            tell_room(room,"%^MAGENTA%^"+ob->QCN+" dives away at the last instant, avoiding most of the breath!",({ player, ob }));
            if(player->query_property("negative energy affinity"))
                ob->cause_typed_damage(ob,ob->return_target_limb(),dam/2,"cold");
            else
                ob->cause_typed_damage(ob,ob->return_target_limb(),dam/2,"fire");
        }
        else
        {
            if(player->query_property("negative energy affinity"))
            {
                tell_object(player,"%^BOLD%^%^CYAN%^"+ob->QCN+" is horribly frozen by the frost!");
                tell_object(ob,"%^BOLD%^%^CYAN%^You are horribly frozen by the frost!");
                tell_room(room,"%^BOLD%^%^CYAN%^"+ob->QCN+" is horribly frozen by the frost!",({ player, ob}));
                ob->cause_typed_damage(ob,ob->return_target_limb(),dam,"cold");
            }
            else
            {
                tell_object(player,"%^BOLD%^%^RED%^"+ob->QCN+" is seared horribly by the flames!");
                tell_object(ob,"%^BOLD%^%^RED%^You are seared horribly by the flames!");
                tell_room(room,"%^BOLD%^%^RED%^"+ob->QCN+" is seared horribly by the flames!",({ player, ob}));
                ob->cause_typed_damage(ob,ob->return_target_limb(),dam,"fire");
            }
        }
    }
}

void death_attack(object player, object target, int clevel)
{
    object room,
           head;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    death_count = 0;
    
    if(!target->query_property("no death") && !target->fort_save(clevel) && target->query_level() < ( player->query_level() + 10 ))
    {
        head = new("/std/obj/body_part.c");
        head->set_limb(target->query("short"),"head");
        head->move(room);

        tell_object(player,"%^BOLD%^%^BLUE%^You clamp your razor-like jaws onto "+target->QCN+"'s head and grab onto "+target->QO+" with both powerful clawed fists!");
        tell_object(target,"%^BOLD%^%^BLUE%^"+player->QCN+" clamps "+player->QP+" jaws onto your head and grabs your body in "+player->QP+" powerful claws!");
        tell_room(room,"%^BOLD%^%^BLUE%^"+player->QCN+" clamps "+player->QP+" jaws onto "+target->QCN+"'s head and grabs "+target->QP+" body in "+player->QP+" powerful claws!",({ player,target }));

        tell_object(player,"%^RESET%^%^BOLD%^With a mighty heave, you draw your muscular neck back.  You can hear the sound of popping tendons and cracking bones as you %^RED%^pull "
        ""+target->QCN+"'s head free of "+target->QP+" neck%^RESET%^%^BOLD%^!");
        tell_object(target,"%^RESET%^%^BOLD%^You realize in horror as "+player->QCN+" begins to wrench "+player->QP+" neck back, that there's nothing you can do!");
        tell_object(target,"%^RESET%^%^BOLD%^%^RED%^You feel incredible agony in your neck as your spine breaks, and then the world fades into blackness, your life snuffed out!");
        tell_room(room,"%^RESET%^%^BOLD%^You can hear the sound of popping tendons and cracking bones as "+player->QCN+" draws "+player->QP+" powerful neck back, %^RED%^pulling "+target->QCN+"'s "
        "head off of "+target->QP+" shoulders!%^RESET%^",({ player, target }));                                   
        tell_object(player,"%^RESET%^%^BOLD%^%^GREEN%^You toss "+target->QCN+"'s lifeless body aside and crunch the head one final time before spitting it onto the ground!");
        tell_room(room,"%^RESET%^%^BOLD%^%^GREEN%^"+player->QCN+" tosses "+target->QCN+"'s lifeless body aside and crunches "+target->QP+" head before spitting it out on the ground!",({ player, target }));
        target->cause_typed_damage(target,target->return_target_limb(),target->query_max_hp()+400,"untyped");
        target->die();
    }
    else
    {
        tell_object(player,"%^BLUE%^You snap your powerful jaws down at "+target->QCN+"'s head, but "+target->QS+" dodges aside at the last instant, you hit "+target->QP+" shoulder instead!");
        tell_object(target,"%^BLUE%^"+player->QCN+" snaps "+player->QP+" powerful jaws down at your head but you dodge aside at the last instant and "+player->QS+" hits your shoulder instead!");
        tell_room(room,"%^BLUE%^"+player->QCN+" snaps "+player->QP+" powerful jaws down at "+target->QCN+"'s head, but "+target->QS+" dodges aside at the last instant and "+player->QS+" hits "+target->QP+" shoulder instead!",({ player, target }));
        target->cause_typed_damage(target,target->return_target_limb(),roll_dice(clevel,10),get_new_damage_type());                    
    }
}

void swipe_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    swipe_count = 0;
        
    tell_object(player,"%^BOLD%^%^GREEN%^You rake your large claw across, swiping a large arc at your enemies!");
    tell_room(room,"%^BOLD%^%^GREEN%^"+player->QCN+" rakes "+player->QP+" large claw in a wide arc, striking at "+player->QP+" enemies!",player);

    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers;
    
    dam = roll_dice(clevel, 6);
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
            tell_object(ob,"%^ORANGE%^"+player->QCN+"'s claw narrowly misses you!");
        else
        {
            tell_object(ob,"%^BOLD%^"+player->QCN+"'s claw strikes you on the way by!");
            ob->cause_typed_damage(ob,ob->return_target_limb(), dam, "slashing");
        }
    }
}

void sweep_attack(object player, object target, int clevel)
{
    object room,
           *attackers;
           
    int dam;
    
    if(!player || !target)
        return;
    
    room = environment(player);
    
    if(room != environment(target))
        return;
    
    sweep_count = 0;
        
    tell_object(player,"%^ORANGE%^You whip your tail around, trying to sweep the feet from under your enemies!");
    tell_room(room,"%^ORANGE%^"+player->QCN+" whips "+player->QP+" tail around, trying to sweep the feet from under "+player->QP+" enemies!",player);

    attackers = player->query_attackers();
    attackers = shuffle(attackers);
    attackers = sizeof(attackers) > 8 ? attackers[0..7] : attackers;
    
    dam = roll_dice(clevel, 8);
    
    foreach(object ob in attackers)
    {
        if(ob->reflex_save(clevel))
        {
            tell_object(player,"%^ORANGE%^Your tail barely misses "+ob->QCN+" on the way by!");
            tell_object(ob,"%^ORANGE%^"+player->QCN+"'s tail barely misses you on the way by!");
            tell_room(room,"%^ORANGE%^"+player->QCN+"'s tail barely misses "+ob->QCN+" on the way by!",({player,ob}));
        }
        else
        {
            tell_object(player,"%^YELLOW%^You catch "+ob->QCN+" with your tail, knocking "+ob->QO+" from "+ob->QP+" feet!");
            tell_object(ob,"%^YELLOW%^"+player->QCN+" catches you with "+player->QP+" tail, knocking you from your feet!");
            tell_room(room,"%^YELLOW%^"+player->QCN+" catches "+ob->QCN+" with "+player->QP+" tail, knocking "+ob->QO+" from "+ob->QP+" feet!",({player,ob}));
            ob->cause_typed_damage(ob,ob->return_target_limb(), dam, "bludgeoning");
            ob->set_tripped(roll_dice(1,6),"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!");
        }
    }
}
    
    
    
    