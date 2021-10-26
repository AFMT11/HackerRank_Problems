#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

/**
   This challenge consists of, 1 country that has
   multiple towns, each town has multiple offices,
   each office has multiple packages.
*/
struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;


/*
This function its job is to print whatever town object that
is referred to it, and it follows the following pattern
in printing its data;
Town_name:
    0:
        id_0
        id_1
        ...
    1:
        id_2
        id_3
        ...
    ...
*/
void print_all_packages(town t)
{
    int i, j;
    printf("%s:\n", t.name); // print the name of the town

    // for loop to loop for each office in the selected town
    for(i = 0; i < t.offices_count; i++)
    {
        printf("\t");
        printf("%d:\n", i); // print the name of the current office

        // for loop to loop for each package in the selected town in the selected office
        for(j = 0; j < t.offices[i].packages_count; j++)
        {
            printf("\t\t");
            printf("%s\n", t.offices[i].packages[j].id); // print the name of the current package
        }
    }
}

/*
   This function its job is to send the accepted packages
   that are located in the source town of the source office index,
   to the target town of the target office index.
   So, for every package accepted by the target office will be
   transferred from its current office of town X into the new office
   of town Y or even town X, and all the packages that are not be
   accepted by the target office it will be placed at the tail of its
   office queue.
*/
void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index)
{
    int i, j;

    /* variable that stores the number of
       packages that are accepted by the target office,
       in order to use that number in addition to the number
       of packages of the target office to reallocate a new
       size in the heap for the target office.
    */
    int No_Accepted_Packages = 0;

    // A variable that stored the number of packages that is stored in the source target
    int source_pointer = source->offices[source_office_index].packages_count;

    /* Two variables to store the minimum, and the maximum
       accepted weights of the packages that can be stored
       in the target office.
    */
    int package_min_weight = target->offices[target_office_index].min_weight;
    int package_max_weight = target->offices[target_office_index].max_weight;

    /* Two variables to temporary store the weight and name
       name of the first package of the source office queue.
    */
    int package_0_weight;
    char* package_0_data;

    /*  So, first things first, a for loop in order to calculate
        the number of accepted packages of source office by the
        target office.
    */
    for(i = 0; i < source_pointer; i++)
    {
        /*  Check if the weight of the source office package is
            bigger than or equal to the minimum accepted weight
            that can be stored by the target office, and also
            Check if the weight of the source office package is
            smaller than or equal to the maximum accepted weight
            that can be stored by the target office, and if the
            two conditions are true then increase the number of
            accepted packages by 1.
        */
        if(source->offices[source_office_index].packages[i].weight >= package_min_weight && source->offices[source_office_index].packages[i].weight <= package_max_weight)
        {
            No_Accepted_Packages++;
        }
    }

    /*  Reallocate the size of the target office with the new size
        which is the number of accepted packages sent by the source
        office, plus the number of packages that are originally the
        target office created with.
    */
    target->offices[target_office_index].packages = realloc(target->offices[target_office_index].packages, sizeof(package) * (No_Accepted_Packages + target->offices[target_office_index].packages_count));

    /*  The most important loop that does all the job for us!
        First, we store the weight and the name of the first
        package of the source office in the previously declared
        variables.
        Second, we swap the weight and name of each all packages
        of source office to the left by one, which means that the
        first package will has the weight and name of the second
        package and the second package will has the weight and name
        of the third package and so forth.
        Third, we do the same check we done early, {Check if the
        weight of the first source office package is bigger than or
        equal to the minimum accepted weight that can be stored
        by the target office, and also Check if the weight of
        the first source office package is smaller than or equal to
        the maximum accepted weight that can be stored by the
        target office} and if the two conditions are true then
        we assign the weight and name of the first package of the
        source office (that we already stored their values in the
        two variables package_0_weight, package_0_data) to the next
        place index of the target office, and simply that index is
        the number of package count of that target office, so if
        there is only one package at the target office, then the
        package count variable will has the value of 1, then the
        next place to store our package sent from the source office
        into the target office is the index of the package count of
        the target office which is 1 as the first package is at index 0!
        and under the same condition after storing the data of the
        first index of the source office in the corresponding index in
        the target office we increase the number of package count of
        the target office as it make sense to increase it as the number
        of package stored at the office is increased by 1 and also
        as when we want to store another package at the target office
        it will be stored at that new index (package count), and lastly
        decrease the number of package count of the source office by one
        as well, as indeed the number of packages stored in the source
        office is decreased by one.
        and On the other hand, if the package is not accepted by the
        target office, then we assign the weight and name of the first
        package of the source office _Rejected package_ (that we already
        stored their values in the two variables package_0_weight, package_0_data)
        to the last index of the source office, that index is equal to
        (package count of source office - 1), that's it!
        Forth, and after the for loop, we reallocate the size of the
        source office to the new size based on the new package count
        variable which its value is decreased every time a package is
        sent successfully to the target office.
    */
    for(i = 0; i < source_pointer; i++)
    {
        package_0_weight = source->offices[source_office_index].packages[0].weight;
        package_0_data = source->offices[source_office_index].packages[0].id;

        // Swap the value of packages
        for(j = 0; j < source_pointer - 1; j++)
        {
            source->offices[source_office_index].packages[j].weight = source->offices[source_office_index].packages[j+1].weight;
            source->offices[source_office_index].packages[j].id = source->offices[source_office_index].packages[j+1].id;
        }

        if(package_0_weight >= package_min_weight && package_0_weight <= package_max_weight)
        {
            target->offices[target_office_index].packages[target->offices[target_office_index].packages_count].weight = package_0_weight;
            target->offices[target_office_index].packages[target->offices[target_office_index].packages_count].id = package_0_data;

            target->offices[target_office_index].packages_count++;
            source->offices[source_office_index].packages_count--;
        }
        else
        {
            source->offices[source_office_index].packages[source->offices[source_office_index].packages_count - 1].weight = package_0_weight;
            source->offices[source_office_index].packages[source->offices[source_office_index].packages_count - 1].id = package_0_data;
        }
    }
    source->offices[source_office_index].packages = realloc(source->offices[source_office_index].packages, sizeof(package) * source->offices[source_office_index].packages_count);
}

/*
    This function its job is find the town with the most
    number of packages stored in it.
*/
town town_with_most_packages(town* towns, int towns_count)
{
    int i, j, k;
    int No_Packages = 0;
    int Temp_No_Packages = 0;
    town biggest_town;

    /*  for loop to check for every town if it has
        the most number of packages or not, and it
        so as following:
        for each town a nested for loop will be
        responsible for counting the number of packages
        assigned to each office of that town, it count
        the number of packages as for each office it
        adds the number of its packages to the variable
        Temp_No_Packages, and for every office in that
        town it will add the number of packages of each
        office to the variable Temp_No_Packages, and after
        that and at the same iteration of the biggest for
        loop (Not the nested one), it checks if the value
        of the variable No_Packages is smaller than the
        value of the variable Temp_No_Packages, and if so,
        then assign the value of Temp_No_Packages to the
        variable No_Packages, and assign the current town
        to the object biggest_town which its job is to
        store the town of the most number of packages.

        and for the next town, it will do the sames steps
        from counting the number of packages using the variable
        Temp_No_Packages, then go and check if the value of
        No_Packages is smaller than the value of Temp_No_Packages
        and if so, that means that the previous town has less
        number of packages than the current one which by that it
        will execute the body of if condition which states at
        that the value of No_Packages will be updated with the
        current number of packages that is stored in Temp_No_Packages,
        but if no, that means that the first town has number of
        packages bigger than the current one which by that it won't
        do anything and the object biggest_town won't be updated
        with any value, as well as the value of No_Packages!
    */
    for(i = 0; i < towns_count; i++)
    {
        for(j = 0; j < towns[i].offices_count; j++)
        {
            Temp_No_Packages += towns[i].offices[j].packages_count;
        }

        if(No_Packages < Temp_No_Packages)
        {
            No_Packages = Temp_No_Packages;
            biggest_town = towns[i];
        }
        Temp_No_Packages = 0;
    }
    return biggest_town;
}

/*
    This function its job is to find the town we are searching
    for by the name of that town only.
*/
town* find_town(town* towns, int towns_count, char* name)
{
    int i,j,indicator = 0;
    town *tt = NULL;

    /*  this for loop check for character-character for the
        name we searching for and for the name of the towns
        itself.
        So, it checks for the first character at both
        the name of the current town, and the input name,
        and if they are equal then we check if the following
        character to the current character we are at right now
        is not equal to "\0" (Null character) or not, if it
        is true (Not equal to Null) then it will go to check for
        the next character of both name of the current town
        and the input name, and if the condition is false and
        the second character of both variables are not equal
        to each other then if will go out of the if condition
        and go for the next iteration which means the next town
        to check.
        if the current character of both variables is the same, but
        the following character to the current character we are at
        right now is equal to "\0" (Null character) which means
        that the if condition is false and it will go to execute
        the body of else statement which states that the town is
        found and its address will be stored at the pointer tt.
    */
    for(i = 0; i < towns_count; i++)
    {
        if(towns[i].name[0] == name[0])
        {
            if(name[1] != '\0')
            {
                if(towns[i].name[1] == name[1])
                {
                    if(name[2] != '\0')
                    {
                        if(towns[i].name[2] == name[2])
                        {
                            if(name[3] != '\0')
                            {
                                if(towns[i].name[3] == name[3])
                                {
                                    if(name[4] != '\0')
                                    {
                                        if(towns[i].name[4] == name[4])
                                        {
                                            if(name[5] != '\0')
                                            {
                                                if(towns[i].name[5] == name[5])
                                                {
                                                    tt = &towns[i];
                                                }
                                            }
                                            else
                                            tt = &towns[i];
                                        }
                                    }
                                    else
                                    tt = &towns[i];
                                }
                            }
                            else
                            tt = &towns[i];
                        }
                    }
                    else
                    tt = &towns[i];
                }
            }
            else
            tt = &towns[i];
        }
    }
    return tt;
}

/*
    The code below is unchangeable
*/
int main()
{
	int towns_count, i, j, k;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
