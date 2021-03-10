// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Written by Sulam    (91-01-19)
// Modifed by Buddha   (92-02-18)
// Updated by Pallando (93-05-25)

// Clear unused command objects from memory.
mapping props;
void clean_up()
{
    destruct(this_object());
}

// Prevent shadowing of commands.
int query_prevent_shadow()
{
    return 1;
}

int remove()
{
    if (!objectp(this_object())) {
        return 1;
    }
    destruct(this_object());
    return 1;
}

// Needed for commands that read, write or load files.
void create()
{
    seteuid(getuid());
}

void set_property(string prop, mixed value)
{
    if (pointerp(value)) {
        if (!props) {
            props = ([]);
        }
        if (!props[prop] || !pointerp(props[prop])) {
            props[prop] = ({});
        }
        props[prop] += value;
        return;
    } else {
        if (!props) {
            props = ([]);
        }
        if (!props[prop]) {
            props[prop] = value;
        }else
            if (props[prop]) {
                props[prop] += value;
                return;
            }
        props += ([ prop:value]);
    }
}

mixed query_property(string prop)
{
    if (!props) {
        props = ([]);
        return 0;
    }
    return props[prop];
}

void remove_all_properties()
{
    props = ([]);
}

int remove_property(string prop)
{
    if (props && props[prop]) {
        props[prop] = 0;
        return 1;
    }
    return 0;
}

int remove_property_value(string prop, mixed val)
{
    if (props && props[prop]) {
        props[prop] -= val;
        return 1;
    }
    return 0;
}

string* regexp_query_property(string pattern)
{
    string* vars, * prop;

    vars = keys(props);
    prop = regexp(vars, pattern);
    if (!prop) {
        prop = ({});
    }
    return prop;
}
