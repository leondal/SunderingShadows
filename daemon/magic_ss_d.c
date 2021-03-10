#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

// This def is not yet needed for anything
#define MAGIC_SS_D_SAVE "/daemon/save/magic_ss_d"

mapping class_spells;
#include <class_spells.h>

#include <spell_domains_spells.h>

void create()
{
    ::create();
}

/**
 * @param mclass class to query
 * @param special special to query, i.e. specific school, mystery, discipline
 * @return ordered list of spells from L1
 */
string *query_class_special_spells(string mclass, string special)
{
    if (!mapp(class_spell_storage)) {
        return ({});
    }

    if (!arrayp(class_spell_storage[mclass][special])) {
        return ({});
    } else {
        return class_spell_storage[mclass][special];
    }
}

/**
 * @param domain Spell domain to query
 * @return orderer list of spells for a domain from L1 to L9
 */
string *query_domain_spells(string domain)
{
    return DOMAIN_SPELLS[domain];
}

/**
 * @return list of all domains
 */
string *query_domains()
{
    return keys(DOMAIN_SPELLS);
}
