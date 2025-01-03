#include "logg.hpp"
#include "ArduinoJson.h"

#pragma once
#define CONFIG_LITTLEFS_SPIFFS_COMPAT 1

class FileSystemModule {
	private:
	static FileSystemModule* pinstance_;
	Logg logg = Logg("FS");

	protected:
	FileSystemModule() {}
	~FileSystemModule() {}

	public:
	static FileSystemModule *GetInstance();
	void onSetup();
	String readFile(String path);
	void writeFile(String path, String content);
	void writeFile(String path, JsonDocument json);
};