// Whenever a new type is added, we need to add it to the following places..
//
// /adm/include/damage_types.h    for the damage type itself
// /adm/include/valid_bonuses.h   for the resistances to the damage (both resistance, and resistance percent)
// /std/Object.c                  for the item properties so they can be tracked on items wear/remove
// Damage types removed: water, air, earth, darkness, light, nature - these aren't real damage types & are making it hard to balance.
// Mental has been left in til I can figure out what to do with psionic spells.
// Silver & cold iron leaving in for use on monsters. N, 8/15.

#define VALID_DAMAGE_TYPES ({ \
        "fire", \
        "cold", \
        "electricity", \
        "acid", \
        "sonic", \
        "bludgeoning", \
        "piercing", \
        "slashing", \
        "silver", \
        "cold iron", \
        "positive energy", \
        "negative energy", \
        "force", \
        "divine", \
        "untyped", \
        "mental", \
    })

#define PHYSICAL_DAMAGE_TYPES ({ \
        "bludgeoning", \
        "piercing", \
        "slashing", \
        "silver", \
        "cold iron", \
    })

#define CRIT_DAMAGE_MODIFIER ([ \
                                  "ooze" : 0, \
                                  "elemental" : 0, \
                              ])
