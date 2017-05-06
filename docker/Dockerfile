FROM agaveapi/torque

MAINTAINER Bryan Lunt <none@none.net>

USER root


RUN yum -y --enablerepo=centosplus install \
		libstdc++-devel \
		torque-drmaa torque-drmaa-devel \
		ant \
		pcre-devel pcre2-devel pcre2-tools

RUN cd /root/ ; curl -O "https://svwh.dl.sourceforge.net/project/swig/swig/swig-3.0.12/swig-3.0.12.tar.gz"; tar -zxvof swig-3.0.12.tar.gz ; cd swig-3.0.12 ; ./configure ; make ; make install

VOLUME /mnt/foobar
