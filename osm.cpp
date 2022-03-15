#include <iostream>
#include <sys/time.h>
#include "osm.h"
#include "math.h"

#define FAIL -1
/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations){
    if(iterations <1){
        return FAIL;
    }
    unsigned int r = iterations%5;
    if(r!=0){
        iterations += 5-r;
    }
    int temp;
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, nullptr);
    for (int i = 0; i <iterations ; i+=5)
    {
        temp = 1 + 1;
        temp = 1 + 1;
        temp = 1 + 1;
        temp = 1 + 1;
        temp = 1 + 1;
    }
    gettimeofday(&tv_end, nullptr);

    double diff_sec = (tv_end.tv_sec - tv_start.tv_sec)*pow(10,9);
    double diff_usec = (tv_end.tv_usec - tv_start.tv_usec)*pow(10,3);
    return (diff_sec+diff_usec)/iterations;
}

/*
 * empty function for measurements
 */
void empty_fun(){

}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations){
    if(iterations <1){
        return FAIL;
    }
    unsigned int r = iterations%5;
    if(r!=0){
        iterations += 5-r;
    }
    int temp;
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, nullptr);
    for (int i = 0; i <iterations ; i+=5)
    {
        empty_fun();
        empty_fun();
        empty_fun();
        empty_fun();
        empty_fun();
    }
    gettimeofday(&tv_end, nullptr);
    double diff_sec = (tv_end.tv_sec - tv_start.tv_sec)*pow(10,9);
    double diff_usec = (tv_end.tv_usec - tv_start.tv_usec)*pow(10,3);
    return (diff_sec+diff_usec)/iterations;

}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations){
    if(iterations <1){
        return FAIL;
    }
    unsigned int r = iterations%5;
    if(r!=0){
        iterations += 5-r;
    }
    int temp;
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, nullptr);
    for (int i = 0; i <iterations ; i+=5)
    {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }
    gettimeofday(&tv_end, nullptr);
    double diff_sec = (tv_end.tv_sec - tv_start.tv_sec)*pow(10,9);
    double diff_usec = (tv_end.tv_usec - tv_start.tv_usec)*pow(10,3);
    return (diff_sec+diff_usec)/iterations;

}

int main(){
    std::cout << "arithmetic: ";
    std::cout << osm_operation_time(100000)<<std::endl;
    std::cout << "empty_func: ";
    std::cout << osm_function_time(100000)<<std::endl;
    std::cout << "system call: ";
    std::cout << osm_syscall_time(100000)<<std::endl;
    return EXIT_SUCCESS;
}


