#pragma once

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>


#include <QtSerialPort/QSerialPort>



class Serial {

public:
    Serial();
    ~Serial();

    bool open();
    void close();

    void write(char* command, int length);
    void Write(char* command, int length) {
        write(command, length);
    }
    void writeCom(char* command, int length) {
        write(command, length);
    }

    void read(char* receive, int length);
    void Read(char* receive, int length) {
        read(receive, length);
    }
    void Readv(char* receive, int length) {
        read(receive, length);
    }
    void readCom(char* receive, int length) {
        read(receive, length);
    }

private:
    QSerialPort *m_serialPort;
};



class SerialDummy {
public:
    SerialDummy();
    ~SerialDummy();

	bool  open() {
		//		port = ser.givePort();           // hole die Port-Adresse
		//		return ser.openCom();
//        return false;
        return true;
	}
	void close() {
		std::cout << "Connection closed\n";
		//		ser.closeCom();
	}
	void write(char* command, int length) {
		
		int i;
		char s[8];
		sprintf_s(s, 8, "%2i | ", length);
		std::cout << "Command: " << s;
		for (i = 0; i < length; i++) {
			std::cout << command[i];
		}
		std::cout << "\n";
		
		//		port->Write(command, length);
	}
	void Write(char* command, int length) {
		write(command, length);
	}
	void read(char* receive, int length) {
        int r = rand() % 1023;
        receive[0] = r % 256;
        receive[1] = r / 256;
		//		port->Readv(receive, length, NULL, false);
	}
	void Read(char* receive, int length) {
		read(receive, length);
	}
	void Readv(char* receive, int length) {
		read(receive, length);
	}

private:
	int dummy;
	//	wxIOBase * port;			    // notwendig f�r die I/O-Befehle
	//	comBasis ser;                    // Objekt f�r die Kommunkikation anlegen

};
