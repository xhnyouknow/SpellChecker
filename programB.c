#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <sys/un.h>  
#include <arpa/inet.h>  
#include <netinet/in.h>  
  
//const int port =88960;  
const char* ip = "127.0.0.1";   
  
int main()  
{  

        while(1){  

	                                                                  char buf[1024];  
								          printf("client please enter: ");  
								          fflush(stdout);  
								          ssize_t size = read(0, buf, sizeof(buf) - 1);  
								          if(size > 0)  
								          {  
									              buf[size - 1] = '\0';  
										          }  
										          else if(size == 0)  
										          {  
											              printf("read is done...\n");  
												              break;  
												          }  
												          else  
												          {  
													              perror("read");  
														              return 4;  
														          }  
														         // printf("client: %s\n", buf); 
                                                                                          int i;
                                                                                          char word[13],check[100];
                                                                                         for(i=0;buf[i]!='.';i++){
                                                                                                  check[i]=buf[i]; 
                                                                                                                                                                                                                                                                                                                                          if ( check[i] >='A' && check[i] <='Z' ) {                                                                                                    check[i]=check[i]+'a'-'A';}
		                                        
				 
		   }
		   check[i]='\0';
		   printf("%s\n",check); 
                   int len=strlen(check);
	
		  
		   int  c=0;
		  
			   while(c<len){
				   for(i=0;(check[c]!=' ')&&(check[c]!='\0')&&(check[c]!=',');i++){
			     word[i]=check[c];
			     c++;
			   }
			      c++;
  //创建套接字,即创建socket   
		      int clt_sock = socket(AF_INET, SOCK_STREAM, 0);   
		      if(clt_sock < 0)  
		      {  
			          //创建失败  
				          perror("socket");  
				          return 1;  
				      }  
				  
				      //绑定信息，即命名socket   
				      struct sockaddr_in addr;   
				      addr.sin_family = AF_INET;   
				      addr.sin_port = htons(88960);   
				      //inet_addr函数将用点分十进制字符串表示的IPv4地址转化为用网络   
				      //字节序整数表示的IPv4地址   
				      addr.sin_addr.s_addr = inet_addr(ip);   
				  
				      //不需要监听  
				  
				      //发起连接  
				//    struct sockaddr_in peer;  
				      socklen_t addr_len = sizeof(addr);  
				      int connect_fd = connect(clt_sock, (struct sockaddr*)&addr, addr_len);  
				      if(connect_fd < 0)  
				      {  
					          perror("connect");  
						          return 2;  
						      }  
						      
						  
						     							          memset(buf, '\0', sizeof(buf));  
														          write(clt_sock, word, strlen(word));  
														          size = read(clt_sock, buf, sizeof(buf));  
														          if(size > 0)  
														          {  
															              buf[size] = '\0';  
																          }  
																          else if(size == 0)  
																          {  
																	              printf("read is done...\n");  
																		              break;  
																		          }  
																		          else   
																		          {  																			              perror("read");  
																				              return 5;  
																				          }  
																				         
int num=atoi(buf);
 printf("server: %d\n", num);  
																				      
   close(clt_sock);
//创建套接字,即创建socket   
		      int clt_sock2 = socket(AF_INET, SOCK_STREAM, 0);   
		      if(clt_sock2 < 0)  
		      {  
			          //创建失败  
				          perror("socket");  
				          return 1;  
				      }  
				  
				      //绑定信息，即命名socket   
				        
				      addr.sin_family = AF_INET;   
				      addr.sin_port = htons(num);   
				      //inet_addr函数将用点分十进制字符串表示的IPv4地址转化为用网络   
				      //字节序整数表示的IPv4地址   
				      addr.sin_addr.s_addr = inet_addr(ip);   
				  
				      //不需要监听  
				  
				      //发起连接  
				//    struct sockaddr_in peer;  
				      addr_len = sizeof(addr);  
				       connect_fd = connect(clt_sock, (struct sockaddr*)&addr, addr_len);  
				      if(connect_fd < 0)  
				      {  
					          perror("connect");  
						          return 2;  
						      }  
						       
						  
						     							          memset(buf, '\0', sizeof(buf));  
								          
														          write(clt_sock, word, strlen(word));  
														          size = read(clt_sock, buf, sizeof(buf));  
														          if(size > 0)  
														          {  
															              buf[size] = '\0';  
																          }  
																          else if(size == 0)  
																          {  
																	              printf("read is done...\n");  
																		              break;  
																		          }  
																		          else   
																		          {  																			              perror("read");  
																				              return 5;  
																				          }  
																				         

 printf("server2: %s\n", buf);  
																				      
   close(clt_sock2);
}

 

  }
																				      return 0;  
}  
