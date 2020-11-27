#pragma once

class IVariantAccessorBase
{
public:
	virtual void free() = 0;
	virtual LPCWSTR GetName() = 0;
	virtual LPCWSTR GetDescription() = 0;
	virtual LPCWSTR SetName(LPCWSTR) = 0;
	virtual LPCWSTR SetDescription(LPCWSTR) = 0;
	virtual bool GetCreationInfo(LPVOID) = 0;
	virtual bool SetCreationInfo(LPVOID) = 0;
	virtual LPVOID PopulateGameOptions(class GameOptions*) = 0;
	virtual bool CreateFileFromBuffer(LPVOID, size_t*) = 0;
};