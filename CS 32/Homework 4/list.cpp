
void listAll(string path, const File* f)  // two-parameter overload
{
	path += f->name();
	cout << path << endl;
	

	
	if (f->files() == NULL)
		return;

	for (unsigned int i = 0; i < f->files()->size(); i++)
	{
		listAll(path+"/", (*f->files())[i]);
	}
}
