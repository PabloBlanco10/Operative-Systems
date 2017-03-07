
//debajo del buf[81]
char host[NI_MAXHOST], serv[NI_MAXSERV];


//printf("CONECTADO \n");
//esto despues del recvfrom 
getnameinfo((struct sockaddr *) &cli, clen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST);
printf(" %s %s \n", host, serv);
//recvfrom
buf[c] = '\0';
buf[c+1] = '\n';

if(buf[0] == 't') {
	//HORA
	char *hora;;;
	hora = system("date");
	sendto(sd, hora, 256, 0, (struct
}else if(buf[0] == 'd'){
	//FECHA
	sendto(sd, "Fecha", 5, 0, (struct
}else if(buf[0] == '1'){
	//SE SALE
	break;
}

//SE COMPILA Y DESDE EL SERVIDOR ./HORA :: 3000 || ::3000
//DESDE EL CLIENTE nc -u ::1 3000
