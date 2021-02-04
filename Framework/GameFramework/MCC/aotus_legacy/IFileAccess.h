#pragma once
#pragma warning(disable:4996)

enum class FileAccessType
{
	Read,
	Write,

	kCount
};

class IFileAccess
{
public:
	IFileAccess(LPCSTR, ...);
	~IFileAccess();

	bool FileOpen(FileAccessType);
	void FileClose();

	char *FileRead(size_t &);

	void FileWrite(char *, size_t);

	LPCSTR get_filepath();

private:
	char s_filePath[MAX_PATH] = {};
	FILE *s_filepath = 0;

	char *s_buffer = 0;
	size_t s_size = 0;
};