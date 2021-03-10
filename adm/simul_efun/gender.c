/**
 * @file
 * @brief Funs for pronoun declinsion for different genders
 */


string possessive(mixed val)
{
    switch (objectp(val) ? (string)val->query_gender() : (string)val) {
    case "male": return "his";
    case "female": return "her";
    case "other": return "their";
    default: return "its";
    }
}

string nominative(mixed val)
{
    switch (objectp(val) ? (string)val->query_gender() : (string)val) {
    case "male": return "he";
    case "female": return "she";
    case "other": return "they";
    default: return "it";
    }
}

string objective(mixed val)
{
    switch (objectp(val) ? (string)val->query_gender() : (string)val) {
    case "male": return "him";
    case "female": return "her";
    case "other": return "them";
    default: return "it";
    }
}
