#ifndef ABI_AFC_INTERNAL_AFC_FILESYSTEM_H_
#define ABI_AFC_INTERNAL_AFC_FILESYSTEM_H_
//////////////////////////////////////////////////////////////////////////
#include <fcntl.h>
#include <libimobiledevice/afc.h>
//////////////////////////////////////////////////////////////////////////
namespace afc{
	namespace internal{
		class timeval{
		public:
			long    tv_sec;
			long    tv_usec;
		};
		struct StatAttr{
			int	st_mode;        //�ļ���Ӧ��ģʽ���ļ���Ŀ¼��
			ino_t	st_ino;            //inode�ڵ��
			dev_t	st_dev;           //�豸����
			dev_t	st_rdev;          //�����豸����
			unsigned long	st_nlink;         //�ļ���������
			unsigned long	st_uid;            //�ļ�������
			unsigned long	st_gid;            //�ļ������߶�Ӧ����
			off_t	st_size;          //��ͨ�ļ���Ӧ���ļ��ֽ���
			time_t	st_atime;        //�ļ���󱻷��ʵ�ʱ��
			time_t	st_mtime;       //�ļ���������޸ĵ�ʱ��
			time_t	st_ctime;        //�ļ�״̬�ı�ʱ��
			time_t	st_birthtime;
			size_t	st_blksize;     //�ļ����ݶ�Ӧԭ���С
			size_t	st_blocks;      //�ļ����ݶ�Ӧ�Ŀ�����
		};
		struct StatByte{
			uint64_t totalspace;
			uint64_t freespace;
			uint64_t blocksize;
		};
		int ifuse_getattr(afc_client_t afc,const char *path,struct StatAttr* stbuf);
		int ifuse_readdir(afc_client_t afc,const char *path,char ***dirs = NULL);
		int ifuse_open(afc_client_t afc,const char *path,uint64_t* fi,int flag = O_RDONLY);
		int ifuse_create(afc_client_t afc,const char *path,uint64_t *fi,int flag = O_RDONLY);
		int ifuse_read(afc_client_t afc, char *buf, size_t size, off_t offset,uint64_t fi);
		int ifuse_write(afc_client_t afc,const char *path, const char *buf, size_t size, off_t offset,uint64_t fi);
		int ifuse_utimens(afc_client_t afc,const char *path, const timeval tv[2]);
		int ifuse_release(afc_client_t afc,uint64_t fi);
		int ifuse_statfs(afc_client_t afc,const char *path,StatByte* bytes);
		int ifuse_truncate(afc_client_t afc,const char *path, off_t size);
		int ifuse_ftruncate(afc_client_t afc,const char *path, off_t size,uint64_t fi);
		int ifuse_symlink(afc_client_t afc,const char *target, const char *linkname);
		int ifuse_link(afc_client_t afc,const char *target, const char *linkname);
		int ifuse_unlink(afc_client_t afc,const char *path);
		int ifuse_rename(afc_client_t afc,const char *from, const char *to);
		int ifuse_mkdir(afc_client_t afc,const char *dir);
	}
}
//////////////////////////////////////////////////////////////////////////
#endif