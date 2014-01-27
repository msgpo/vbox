 * Copyright (C) 2009-2014 Oracle Corporation
 *
 * @deprecated  Only used for legacy code and writing.  Migrate new code to the
 *              VFS interface, add the write part when needed.
 *
 * Creates a Tar archive.
 * Use the mask to specify the access type.
 * @param   pszTarname     The file name of the tar archive to create.  Should
 *                         not exist.
RTR3DECL(int) RTTarOpen(PRTTAR phTar, const char *pszTarname, uint32_t fMode);
 * @param   pcbRead        Where to return how much we actually read.  If NULL
 *                         an error will be returned for a partial read.
 * @param   pcbWritten     Where to return how much we actually wrote.  If NULL
 *                         an error will be returned for a partial write.
#endif