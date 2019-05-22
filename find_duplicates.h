#include <unordered_map>

vector<string> find_duplicates(DataGenerator& generator) {
    /*
     * Find duplicates in the given data.
     *
     * The `generator` provides a forward iterator over strings
     * for traversing the data, so it can be iterated for example
     * using a `for` cycle:
     *
     *   for (const string& item : generator) {...}
     *
     * The `generator` can be traversed multiple times.
     *
     * The goal is to return a vector of duplicated entries,
     * reporting each duplicated entry only once, in the order
     * of their first occurrence in the data.
     */
	unordered_map<string, char> map_of_unique_lines;
    vector<string> return_vector;
    for (const string& item : generator){

//		try {
//			map_of_unique_lines.at(item); //this can throw error, meaning item does not exist
//			//map_of_unique_lines[item] = map_of_unique_lines[item] + 1;
//			return_vector.push_back(item);
//		}
//		catch (const out_of_range &e)
//		{
//			map_of_unique_lines[item] = 'a';
//		}
		//Try-catch method is slow

        if (map_of_unique_lines.find(item) == map_of_unique_lines.end()){
            //not found, add item
            map_of_unique_lines[item] = 'a';
        }else{
            //map_of_unique_lines[item] = map_of_unique_lines[item]+1;
            return_vector.push_back(item);
        }
    }
	std::reverse(return_vector.begin(), return_vector.end());

    return return_vector;
}
