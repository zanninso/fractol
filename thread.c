/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:53:21 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/13 20:12:52 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
# define MAX_THREAD 2000
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread %d\n",*((int *)vargp)); 
    return NULL; 
} 
   
int main() 
{
    int i = 0;
    pthread_t thread_id[MAX_THREAD]; 
    printf("Before Thread\n");
    while(i < MAX_THREAD){
        pthread_create(&thread_id[i], NULL, myThreadFun, &thread_id[i]); 
        i++;
    }
    i = 0;
    while(i < MAX_THREAD){
        pthread_join(thread_id[i], NULL);
        i++;
    }
    
    printf("After Thread\n"); 
    exit(0); 
}