#include <std.h>
#include <daemons.h>

#define SHAPE_DIR "/std/races/shapeshifted_races/"

inherit FEAT;

void create() {
    ::create();
    feat_type("instant");
    feat_category("WildernessLore");
    feat_name("shapeshift");
    feat_prereq("Druid L4");
    feat_syntax("shapeshift SHAPE [| VARIANT]");
    feat_desc("The shapeshift feat will allow the user to change into another form. Whileshapeshifted, users maintain their intelligence but also gain the mannerisms and instinctsof their shapeshifted form, but they are able to overcome their animal instincts and actof their own free will. Users in animal form can freely speak with other animals, butwill need a special feat to communicate with others who do not understand the animal'slanguage. All equipment worn and carried by the user is absorbed into the shapeshiftingprocess and, with the exception of healing vials, will be unusuable until the user returnsto his or her normal form. Equipment bonuses for worn and wielded armor and weapons willremain when the user is shapeshifted. In addition, bird shape can use <wing> command. Different forms are learned by the druid as theygrow in strength, as follows:

  L4 Wolf. Variants: coyote, fox, hyena, jackal, wolverine, worg
  L4 Small Animal. Variants: ferret, lizard, mole, mongoose, monkey, mouse, rabbit, raccoon, rat, skunk, squirrel
  L11 Bear. Variants: grizzly bear, kodiak bear, polar bear, black bear, brown bear, panda
  L11 Large animal. Variants: ape, bison, boar, buffalo, camel, deer, goat, horse, moose
  L14 Bird. Variants: crow, eagle, falcon, hawk, owl, raven, vulture, goose
  L17 Cat. Variants: cheetah, jaguar, leopard, lion, lynx, ocelot, panther, tiger

You will be able to set descriptions, speech messages for each form, but it will be shared between variants, and for many descriptions it means you can have just one variant of each form. For descriptions variants work as subraces and you can refer to them in adjectives with $SR keyword.

Dragon: refer to <help wild shape dragon>
Elemental: refer to <help wild shape elemental>");
    set_target_required(0);
    allow_blind(1);
    set_required_for(({"wild knowledge","wild speech","wild spellcraft","wild shape dragon","wild shape elemental","savage instincts i","savage instincts ii","savage instincts iii","wild spellcraft","mastery of fang and claw"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob) {
    if(!objectp(ob)) { return 0; }

    if((int)ob->query_class_level("druid") < 4) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

int cmd_shapeshift(string str){
    object feat;
    if(!objectp(TP)) { return 0; }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void unshift() {
// this func is only called if they are shifted and going to another. So, calling quiet func to allow form to form shifting. N, 2/14.
    object shape;

    if(objectp(shape = caster->query_property("shapeshifted"))) {
        shape->reverse_shape(caster,1);
    }
    return;
}


void execute_feat() {
    if(caster->query_casting()) {
        tell_object(caster,"%^BOLD%^You can't shapeshift while you're casting a spell.");
        dest_effect();
        return;
    }
    if(caster->query_bound() && (arg || arg != "")) {
        tell_object(caster,"%^BOLD%^You can only shift back into your normal form while you're bound.");
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^GREEN%^You focus on your connection to the natural world around you, letting yourself "
        "become one with the wilds.");
    tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+"'s face takes on a countenance of serenity.",caster);
    caster->set_property("using instant feat",1);
    call_out("change_me",5);
    return;
}


void change_me() {
    object shape;
    string myrace="",subrace="",oksubraces=({});

    if(!objectp(caster)) { return; }

    caster->remove_property("using instant feat");
    ::execute_attack();

    if(caster->query_casting()) {
        tell_object(caster,"%^BOLD%^You can't shapeshift while you're casting a spell.");
        dest_effect();
        return;
    }
    if(caster->query_bound() && (arg || arg != "")) {
        tell_object(caster,"%^BOLD%^You can only shift back into your normal form while you're bound.");
        dest_effect();
        return;
    }

    if(stringp(arg)) {
        if(sscanf(arg,"%s | %s",myrace,subrace) != 2) {
            myrace = arg;
            subrace = arg;
        }
    }
    if((myrace == "large animal" || myrace == "small animal") && myrace == subrace) subrace = "animal"; //default small/large race setting.

    switch(myrace) {
    case "wolf":
        shape = new(SHAPE_DIR+"druid_wolf.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "small animal":
        shape = new(SHAPE_DIR+"druid_small_animal.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "bear":
        if((int)caster->query_class_level("druid") < 11) {
            tell_object(caster,"You must be at least L11 druid in order to shapeshift into a bear.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_bear.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "large animal":
        if((int)caster->query_class_level("druid") < 11) {
            tell_object(caster,"You must be at least L11 druid in order to shapeshift into a large animal.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_large_animal.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "bird":
        if((int)caster->query_class_level("druid") < 14) {
            tell_object(caster,"You must be at least L14 to flap the wings.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_bird.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "cat":
        if((int)caster->query_class_level("druid") < 17) {
            tell_object(caster,"You must be at least L17 druid in order to shapeshift into a cat.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_cat.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "dragon":
        if(!FEATS_D->usable_feat(caster,"wild shape dragon")) {
            tell_object(caster,"You need the feat 'wild shape dragon' in order to shapeshift into a dragon.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_dragon.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;

    case "elemental":
        if(!FEATS_D->usable_feat(caster,"wild shape elemental")) {
            tell_object(caster,"You need the feat 'wild shape elemental' in order to shapeshift into an elemental.");
            dest_effect();
            return;
        }
        shape = new(SHAPE_DIR+"druid_elemental.c");
        oksubraces = (string *)shape->query_subraces();
        if(!sizeof(oksubraces)) subrace = myrace; // default to basic race if no settings.
        if(member_array(subrace,oksubraces) == -1) subrace = myrace; // default to basic race if not eligible.
        unshift();
        shape->init_shape(caster,subrace);
        return;


    default:
        if(!objectp(shape = caster->query_property("shapeshifted"))) {
          // hijacking for a plot-related character setup! N, 2/15
          if((string)caster->query_name() == "thellanora") {
            unshift();
            new(SHAPE_DIR+"lythari_wolf.c")->init_shape(caster,"wolf");
          }
          return;
        }
        shape->reverse_shape(caster);
        return;
    }

    ::execute_feat();
    return;
}

void dest_effect() {
    ::dest_effect();
    remove_feat(TO);
    return;
}
