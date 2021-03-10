/**********************************************/
/* Murmur@Nightmare                           */
/* Tinks@Circle                               */
/* I use this file to make armour and weapons */
/**********************************************/

#define ARMOUR_TYPES ({ \
    "helmet", \
    "visor", \
    "body armour", \
    "armour", \
    "cloak", \
    "shield", \
    "glove", \
    "ring", \
    "belt", \
    "pants", \
    "boot", \
    "sock" \
})

#define ARMOUR_MIN_AC ([ \
    "helmet" : 1, \
    "visor" : 1, \
    "body armour" : 1, \
    "armour" : 1, \
    "cloak" : 1, \
    "shield" : 1, \
    "glove" : 1, \
    "ring" : 1, \
    "belt" : 1, \
    "pants" : 1, \
    "boot" : 1, \
    "sock" : 1 \
])


#define ARMOUR_MAX_WEIGHT ([ \
    "helmet" : 2000, \
    "visor" : 1000, \
    "body armour" : 6000, \
    "armour" : 6000, \
    "cloak" : 2000, \
    "shield" : 2000, \
    "glove" : 2000, \
    "ring" : 1000, \
    "belt" : 1000, \
    "pants" : 3000, \
    "boot" : 2000, \
    "sock" : 1000, \
])

#define ARMOUR_MAX_AC ([ \
    "helmet" : 2, \
    "visor" : 1, \
    "body armour" : 6, \
    "armour" : 6, \
    "cloak" : 2, \
    "shield" : 2, \
    "glove" : 2, \
    "ring" : 1, \
    "belt" : 1, \
    "pants" : 3, \
    "boot" : 2, \
    "sock" : 1, \
])

#define ARMOUR_MIN_VALUE ([ \
    "helmet" : 0, \
    "visor" : 0, \
    "body armour" : 0, \
    "armour" : 0, \
    "cloak" : 0, \
    "shield" : 0, \
    "glove" : 0, \
    "ring" : 0, \
    "belt" : 0, \
    "pants" : 0, \
    "boot" : 0, \
    "sock" : 0 \
])

#define ARMOUR_MAX_VALUE ([ \
    "helmet" : 200, \
    "visor" : 150, \
    "body armour" : 300, \
    "armour" : 300, \
    "cloak" : 200, \
    "shield" : 200, \
    "glove" : 150, \
    "ring" : 250, \
    "belt" : 150, \
    "pants" : 200, \
    "boot" : 250, \
    "sock" : 100 \
])

#define ARMOUR_MIN_WEIGHT ([ \
    "helmet" : 200, \
    "visor" : 100, \
    "body armour" : 600, \
    "armour" : 400, \
    "cloak" : 100, \
    "shield" : 300, \
    "glove" : 50, \
    "ring" : 40, \
    "belt" : 60, \
    "pants" : 140, \
    "boot" : 120, \
    "sock" : 100 \
])

#define WEAPON_TYPES ({ \
    "blade", \
    "knife", \
    "projectile", \
    "blunt", \
    "two handed" \
})

#define WEAPON_MIN_AC ([ \
"blade" : 0, \
"knife" : 0, \
"projectile" : 0, \
"blunt" : 0, \
"two handed" : 0 \
])

#define WEAPON_MAX_AC ([ \
    "blade" : 3, \
    "knife" : 3, \
    "projectile" : 3, \
    "blunt" : 3, \
    "two handed" : 3 \
])

#define WEAPON_MIN_WC ([ \
"blade" : 1, \
"knife" : 1, \
"projectile" : 1, \
"blunt" : 1, \
"two handed" : 1 \
])

#define WEAPON_MAX_WC ([ \
    "blade" : 20, \
    "knife" : 20, \
    "projectile" : 20, \
    "blunt" : 20, \
    "two handed" : 40 \
])

#define WEAPON_MIN_VALUE ([ \
    "blade" : 1, \
    "knife" : 1, \
    "projectile" : 1, \
    "blunt" : 1, \
    "two handed" : 1 \
])

#define WEAPON_MAX_VALUE ([ \
    "blade" : 400, \
    "knife" : 400, \
    "projectile" : 400, \
    "blunt" : 400, \
    "two handed" : 400 \
])

#define WEAPON_MIN_WEIGHT ([ \
    "blade" : 350, \
    "knife" : 200, \
    "projectile" : 350, \
    "blunt" : 350, \
    "two handed" : 350 \
])

// These are the modifiers from combat that determine how much exp and skill 
// pts are given out                   
// Experience given for killing a monster
#define DEATH_EXP_MOD              1/50  
// Experience given for doing damage to a monster
#define ATTACK_DAMAGE_EXP_MOD      1/2           
// Attack skill points given for doing damage to a monster
#define ATTACK_ATTACK_SKILL_MOD    1/2                    
// Melee skill points given for doing damage to a monster
#define ATTACK_MELEE_SKILL_MOD     1/2                  
// Double wielding skill points given for doing damage to a monster
#define ATTACK_DOUBLE_SKILL_MOD    1/2
// Weapon type skill points given for doing damage to a monster
#define ATTACK_TYPE_SKILL_MOD      1/2
