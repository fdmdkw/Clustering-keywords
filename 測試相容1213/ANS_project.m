clc
clear all

datalist = dir('./*txt'); % Åª¨útxt
load('Ans_all.mat');
tp = 0;
fp = 0;

for i = 1: length(datalist(1:end,1))
    str = fileread(datalist(i).name);
    name = regexp(datalist(i).name,'(\d+)','tokens');
    for j = 1:length(Ans(:,1))        
        if str2double(name{1,1}{1,1}) == Ans(j,1)
                    
           if  Ans(j,2) == str2double(str)
               tp = tp + 1;
           else
               fp = fp + 1;
           end
           
        else
            continue;
        end

    end
end
precision = tp/(tp+fp);
fprintf(1,'precision = %1.2f %%',precision*100);
%% test
% for i = 1: length(Ans)
%     
% Ans_filename = [num2str(Ans(i,1)) 'a'];
% a = Ans(i,2);
% fid = fopen([Ans_filename '.txt'],'w'); % ¼g¤JÀÉ®×
% fprintf(fid,'%d',a);
% fclose(fid);
% 
% end