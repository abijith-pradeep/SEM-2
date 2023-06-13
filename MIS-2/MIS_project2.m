clc;clear;close all;
disp('***********************************************************************');
disp('                                  Cryptography                         ');
disp('***********************************************************************');
text=input('Enter The plain Text : ','s'); %Input for the plain text
n = input('Enter the key size : (Must be 4,9,....) : ');
n=sqrt(n);
upperString=upper(text); %Converting the string to capital letters
charText=char(upperString); %Converting from string to char
Actualtext=charText-65; %Substracting 65 to obtain the letters in the range of 0-25
jk=Actualtext;
if(rem(size(Actualtext),n)==[1 0])
    Message=reshape(Actualtext,n,length(Actualtext)/n);  
    Message = [Message]';%Converting a row matrix to a matrix with n columns   
else
Actualtext=[Actualtext 25]; %Adding an extra dummy character at the end 
    Message=reshape(Actualtext,n,length(Actualtext)/n);
    Message = [Message]';   
end
theKey=0;
for i=1:(n^2)
key=input('Enter the key: ');
theKey=[theKey key];
end
realkey=theKey(2:end);
rrealkey=realkey+65;
Key=char(rrealkey)
Actualkey=reshape(realkey,n,n)’; 
if(det(Actualkey) ~= 0) 
    Encmessage=Message*Actualkey;%Multiplying the plain text with the key
    Encmessage=mod(Encmessage,26);%Finding the mod of the multiplied matrix
    Encmessage=[Encmessage]';
    encmatrix=reshape(Encmessage,1,length(Actualtext));%Changing the matrix back to row matrix
    encmatrix=encmatrix+65;    
    Encrypted=char(encmatrix)
else
    disp('The key matrix is not invertible');
end
%Decrypting
    j=mod(det(Actualkey),26);
    for b = 1:26
        d(b)=j*b;
        h(b)=rem(d(b),26);
    end
    % m =[3 10 20;20 9 17;9 4 17;]
    h=uint8(h);
    m=find(h==1);
    if(m ~=0)    
        invk=m.*adjoint(Actualkey);
    else
        disp('Enter Another Key');
        return;
    end
Encmessage=[Encmessage]';
decmsg=Encmessage*invk; %Multiplying inverse with the encrypted message
decmsg=mod(decmsg,26);

decmsg=[decmsg]';
decmsg=reshape(decmsg,1,length(Actualtext));
decmsg=decmsg+65;
if(rem(length(jk),n)==0)
    decmsg=uint8(decmsg);
    v=find(decmsg==91);
    decmsg(v)=65;
char(decmsg)
else
    decmsg=decmsg(1:length(Actualtext)-1);
    decmsg=uint8(decmsg);
    v=find(decmsg==91);
    decmsg(v)=65;
    char(decmsg)
end
